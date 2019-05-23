#include<iostream>
#include<poll.h>
#include<unistd.h>
using namespace std;

int main()
{
     struct pollfd rfds;
     rfds.fd=0;
     rfds.events=POLLIN;                                                                                                                                                            
     rfds.revents=0;
      while(1)
      {
          int timeout=1000;
          switch(poll(&rfds,1,-1))
          {
            case 0:
                  cout<<"timeout..."<<endl;
                  break;
           case -1:
                 cout<<"poll error!"<<endl;
                 break;
           default:
                  if(rfds.revents&POLLIN)
                 {
                    char buf[1024];
                     ssize_t s=read(rfds.fd,buf,sizeof(buf)-1);
                    if(s>0)
                     {
                         buf[s-1]=0;
                          cout<<"echo# "<<buf<<endl;
                      }
                  }
                  break;
         }
      }
      return 0;
 }