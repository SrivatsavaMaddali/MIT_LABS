//CLIENT

#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 50

int main()
{
int choice;
int sockfd,retval;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;
int num[5]={ 5, 4, 3, 8, 9};
char buff[MAXSIZE];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("\nSocket Creation Error");

}
printf("%i",sockfd);
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==-1)
{
printf("Connection error");

}


sentbytes=send(sockfd,num,sizeof(num),0);

if(sentbytes==-1)
{
printf("!!");
close(sockfd);
}
printf("Enter the choice\n");
scanf("%d",&choice);
send(sockfd,choice,sizeof(choice),0);


recedbytes=recv(sockfd,num,sizeof(num),0);
for(int i=0;i<5;i++)
printf("%d",num[i]);

printf("\n");
close(sockfd);
}
