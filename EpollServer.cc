  1 #include<iostream>
  2 #include<stdlib.h>
  3 #include<sys/epoll.h>
  4 #include<strings.h>
  5 #include<arpa/inet.h>
  6 #include<netinet/in.h>
  7 #include<sys/socket.h>
  8 #include<sys/types.h> 
  9 #include<unistd.h> 
 10 using namespace std; 
 11  
 12 class Sock 
 13 { 
 14     private: 
 15         int sock; 
 16         int port; 
 17     public: 
 18         Sock(const int& port_):port(port_) 
 19         { 
 20         } 
 21         int Socket() 
 22         { 
 23             sock=socket(AF_INET,SOCK_STREAM,0);
 24             if(sock<0)                                                                                                                                                                                                                  
 25             {
 26                 cerr<<"sock error"<<endl;
 27                 exit(2);
 28             }
 29             int opt=1;
 30             setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
 31         }
 32         int GetSocket()
 33         {
 34             return sock;
 35         }
 36         int Bind()
 37         {
 38             struct sockaddr_in local;
 39             bzero(&local,sizeof(local));
 40             local.sin_family=AF_INET;
 41             local.sin_port=htons(port);
 42             local.sin_addr.s_addr=INADDR_ANY;
 43 
 44             if(bind(sock,(struct sockaddr*)&local,sizeof(local))<0)
 45             {
 46                 cerr<<"bind error"<<endl;
 47                 exit(3);
 48             }
 49         }
 50         int Listen()
 51         {
 52             if(listen(sock,5)<0)
 53             {
 54                 cerr<<"listen error"<<endl;
 55                 exit(4);
 56             }
 57         }
 58         int Accept()
 59         {
 60             struct sockaddr_in peer;
 61             socklen_t len=sizeof(peer);
 62             int sock_=accept(sock,(struct sockaddr*)&peer,&len);
 63             if(sock_<0)
 64             {
 65                 cerr<<"accept error"<<endl;
 66                 return -1;
 67             }
 68             return sock_;
 69         }
 70         ~Sock()
 71         {
 72             close(sock);                                                                                                                                                                                                                
 73         }
 74 
 75 };
 76 
 77 class EpollServer
 78 {
 79     private:
 80         int epfd;
 81         Sock sock;
 82     public:
 83         EpollServer(int port):sock(port)
 84         {
 85             epfd=-1;
 86         }
 87         void InitServer()
 88         {
 89             sock.Socket();
 90             sock.Bind();
 91             sock.Listen();
 92             epfd=epoll_create(256);
 93             if(epfd<0)
 94             {
 95                 cerr<<"epoll_create error!"<<endl;
 96                 exit(5);
 97             }
 98             struct epoll_event ev;
 99             ev.events=EPOLLIN;
100             ev.data.fd=sock.GetSocket();
101 
102             epoll_ctl(epfd,EPOLL_CTL_ADD,sock.GetSocket(),&ev);
103         }
104 
105         void HandlerEvents(int &epfd,Sock &sock,struct epoll_event revs[],int& num)
106         {
107             int listen_sock=sock.GetSocket();
108             struct epoll_event ev;
109             for(auto i=0;i<num;++i)
110             {
111                 int fd=revs[i].data.fd;
112                 uint32_t rev=revs[i].events;
113                 if(rev&EPOLLIN)     //读事件就绪
114                 {
115                     if(fd==listen_sock)
116                     {
117                         int new_sock=sock.Accept();
118                         ev.events=EPOLLIN;
119                         ev.data.fd=new_sock;
120                         epoll_ctl(epfd,EPOLL_CTL_ADD,new_sock,&ev);                                                                                                                                                                     
121 
122                     }
123                     else
124                     {
125                         char buf[4096];
126                         ssize_t s=recv(fd,buf,sizeof(buf)-1,0);
127                         if(s>0)
128                         {
129                             buf[s-1]=0;
130                             cout<<buf<<endl;
131                             ev.events=EPOLLOUT;
132                             ev.data.fd=fd;
133                             epoll_ctl(epfd,EPOLL_CTL_MOD,fd,&ev);  //先处理读事件再关心写事件
134                         }
135                         else if(s==0)
136                         {
137                             cout<<"client quit..."<<endl;
138                             close(fd);
139                             epoll_ctl(epfd,EPOLL_CTL_DEL,fd,NULL);
140                         }
141                         else
142                         {
143                         }
144                     }
145 
146                 }
147                 else if(rev&EPOLLOUT)
148                 {
149                     string http_echo="HTTP/1.0 200 OK\r\n\r\n<html><h1>hello epoll server!!!</h1></html>";
150                     send(fd,http_echo.c_str(),http_echo.size(),0);
151                     close(fd);
152                     epoll_ctl(epfd,EPOLL_CTL_DEL,fd,NULL);
153                 }
154                 else
155                 {
156                 }
157             }
158         }
159         void Start()
160         {
161             int num=0;
162             struct epoll_event revs[64];
163             const int revs_num=64;
164             for(;;)
165             {
166                 int timeout=1000;
167                 switch((num=epoll_wait(epfd,revs,64,-1)))
168                 {                                                                                                                                                                                                                       
169                     case 0:
170                         cout<<"timeout..."<<endl;
171                         break;
172                     case -1:
173                         cout<<"epoll_wait error"<<endl;
174                         break;
175                     defult:
176                         HandlerEvents(epfd,sock,revs,num);
177                         break;
178                 }
179             }
180         }
181 
182         ~EpollServer()
183         {
184         }
185 };
186 
187 void Usage(string proc)
188 {
189     cout<<"Usage:"<<proc<<"port"<<endl;
190 }
191 
192 int main(int argc,char* argv[])
193 {
194     if(argc!=2)
195     {
196         Usage(argv[0]);
197         exit(1);
198     }
199     int port=atoi(argv[1]);
200     EpollServer server(port);
201     server.InitServer();
202     server.Start();
203 }
                                                                                                                
                                                                         