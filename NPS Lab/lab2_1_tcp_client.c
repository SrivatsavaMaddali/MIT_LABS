#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 50

main()
{
int sockfd,retval;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;
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
printf("enter the filename\n");

scanf("%s",buff);


sentbytes=send(sockfd,buff,sizeof(buff),0);

if(sentbytes==-1)
{
printf("!!");
close(sockfd);
}
memset(buff,'\0',sizeof(buff));
recedbytes=recv(sockfd,buff,sizeof(buff),0);
puts(buff);
printf("\n");
if(buff[0]=='N')
close(sockfd);
else if(buff[0]=='F')
{
int choice[1];
while(choice[0]!=4)
{
printf("\n1. Search 2. Replace 3. Reorder 4. Exit\nEnter your choice:");
scanf("%d",&choice[0]);
sentbytes=send(sockfd,choice,sizeof(choice),0);
if(choice[0]==1)
{
char search[10];
printf("Enter string to search:");
scanf("%s",search);
sentbytes=send(sockfd,search,sizeof(search),0);
int count[1];
recedbytes=recv(sockfd,count,sizeof(count),0);
printf("No. of occurences:%d",count[0]);
}
else if(choice[0]==2)
{
}
else if(choice[0]==3)
{
}
else if(choice[0]==4)
{
close(sockfd);
}

}
}
}
