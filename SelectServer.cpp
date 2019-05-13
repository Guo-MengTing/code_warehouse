  1 #include<iostream>                                                                                                                                                                 
  2 #include<sys/types.h>
  3 #include<sys/socket.h>
  4 #include<string>
  5 #include<stdlib.h>
  6 #include<sys/select.h>
  7 #include<arpa/inet.h>
  8 #include<netinet/in.h>
  9 #include<unistd.h>
 10 
 11 
 12 using namespace std;
 13 class Sock
 14 {
 15     private:
 16         int _sock;
 17         string ip;
 18         int port;
 19     public:
 20         Sock(const string& ip_,const int& port_):ip(ip_),port(port_)
 21         {}
 22         int Socket()
 23         {
 24             _sock=socket(AF_INET,SOCK_STREAM,0);
 25             if(_sock<0)
 26             {
 27                 cerr<<"socket error!"<<endl;
 28                 exit(2);
 29             }
 30         }
 31         int GetSocket()
 32         {
 33             return _sock;
 34         }
 35         int Bind()
 36         {
 37             struct sockaddr_in local;
 38             local.sin_family=AF_INET;
 39             local.sin_port=htons(port);
 40             local.sin_addr.s_addr=inet_addr(ip.c_str());
 41             if(bind(_sock,(struct sockaddr*)&local,sizeof(local))<0)
 42             {
 43                 cerr<<"bind error"<<endl;                                                                                                                                          
 44                 exit(3);
 45             }
 46             return 0;
 47         }
 48         int Listen()
 49         {
 50             if(listen(_sock,5)<0)
 51             {
 52                 cerr<<"listen error"<<endl;
 53                 exit(4);
 54             }
 55             return 0;
 56         }
 57         int Accept()
 58         {
 59             struct sockaddr_in peer;
 60             socklen_t len=sizeof(peer);
 61             int sock=accept(_sock,(struct sockaddr*)&peer,&len);
 62             if(sock>0)
 63             {
 64                 return sock;
 65             }
 66             return -1;
 67         }
 68 
 69         ~Sock()
 70         {
 71             close(_sock);
 72         }
 73 };
 74 
 75 #define FD_DEFAULT -1
 76 class FdArray
 77 {
 78     private:
 79         int *fd_array;
  80         int max_fd;
 81         int size;
 82         int cap;
 83     public:
 84         FdArray(int num):size(0),cap(num)
 85         {
 86             fd_array=new int[num];
 87             for(auto i=0;i<num;++i)
 88             {
 89                 fd_array[i]=FD_DEFAULT;
 90             }
 91         }
 92         int AddFd(int fd)
 93         {
 94             if(size==cap)
 95                 return-1;
 96             fd_array[size]=fd;
 97             size++;
 98         }
 99         int DelFd(int fd)
100         {
101             for(auto i=0;i<size;++i)
102             {
103                 if(fd_array[i]==fd)
104                 {
105                     fd_array[i]=fd_array[size-1];
106                     fd_array[size-1]=FD_DEFAULT;
107                     size--;
108                     break;
109                 }
110             }
111         }
112         void SetReadFds(fd_set &rfds)
113         {
114             for(auto i=0;i<size;++i)
115             {
116                 if(fd_array[i]!=FD_DEFAULT)
117                 {
118                     FD_SET(fd_array[i],&rfds);
119                 }
120             }
121         }
122         int MaxFd()
123         {
124             int max=fd_array[0];                                                                                                                                                   
125             for(auto i=1;i<size;++i)
126             {
127                 if(max<fd_array[i])
128                     max=fd_array[i];
129             }
130             return max;
131         }
132         void HandlerEvents(fd_set &rfds,Sock &listen_sock)
133         {
134             for(auto i=0;i<size;++i)
135             {
136                 if(FD_ISSET(fd_array[i],&rfds))
137                 {
138                     if(fd_array[i]==listen_sock.GetSocket())
139                     {
140                         int sock=listen_sock.Accept();
141                         if(sock>0)
142                         {
143                             cout<<"Get a new link..."<<endl;
144                             AddFd(sock);
145                         }
146                     }
147                     else
148                     {
149                         char buf[4096];
150                         ssize_t s=recv(fd_array[i],buf,sizeof(buf)-1,0);
151                         if(s>0)
152                         {
153                             buf[s]=0;
154                             cout<<buf<<endl;
155                             string http_echo="HTTP/1.0 200 OK\r\n\r\n<html><h1>hello select server!!!</h1></html>";
156                             send(fd_array[i],http_echo.c_str(),http_echo.size(),0);
157                             close(fd_array[i]);
158                             DelFd(fd_array[i]);
159                         }
160                         else if(s==0)
161                         {
162                             cout<<"client quit"<<endl;
163                             close(fd_array[i]);
164                             DelFd(fd_array[i]);
165                         }
166                         else{
167                         }
168 
169                     }
170                 }
171             }
172         }
173 
174         ~FdArray()
175         {
176             delete []fd_array;
177         }
178 };
179 
180 void Usage(string proc_)
181 {
182     cout<<"Usage:"<<proc_<<"ip port"<<endl;
183 }
184 int main(int argc,char *argv[])
185 {
186     if(argc!=3){
187         Usage(argv[0]);
188         exit(1);
189     }
190 
191     string ip=argv[1];
192     int port=atoi(argv[2]);
193     Sock listen_sock(ip,port);
194     listen_sock.Socket();
195     listen_sock.Bind();
196     listen_sock.Listen();
197     
198     FdArray fd_array(sizeof(fd_set)*8);
199     fd_array.AddFd(listen_sock.GetSocket());
200     
201     for(;;)
202     {
203         fd_set rfds;
204         FD_ZERO(&rfds);
205         fd_array.SetReadFds(rfds);
206 
207         struct timeval timeout={0,0};
208         int max_fd=fd_array.MaxFd();
209 
210         switch(select(max_fd+1,&rfds,NULL,NULL,/*&timeout*/NULL)){
211             case 0:
212                 cout<<"timeout..."<<endl;
213                 break;
214             case -1:
215                 cout<<"select error"<<endl;
216                 break;
217             default:
218                 fd_array.HandlerEvents(rfds,listen_sock);
219                 break;
220         }
221     }
222 }                                                                                                                                                                                  
                                                                                                                                                                     222,1        底端


                                                                                                                                                                     124,3-12      66%
                                                                                                                                                                      
                                                                                                                                                                     120,4-13      43%

                                                                                                                                                                     1,18         顶端

                                                                                                             29,3-12       14%

                                                                                                  6,13         顶端
