#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#define MAXSIZE 50

int main()
{
int choice[5];
int num1[2];
int num2[3];
int sockfd,retval;
int recedbytes,recedbytes1,sentbytes;
struct sockaddr_in serveraddr;
int num[5]={ 5, 4, 3, 8, 9};
int temp[5];
for(int i=0;i<5;i++)
{
temp[i]==num[i];
}

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
//while(choice[0]!=4){

printf("Enter the choice\n");
scanf("%d",&choice[0]);
int search[10];
send(sockfd,choice,sizeof(choice),0);
if(choice[0]==1)
{
for(int i=0;i<5;i++)
{
num[i]==temp[i];
}

printf("\nEnter the element to search:");
scanf("%d",&search[0]);
sentbytes=send(sockfd,search,sizeof(search),0);
int srecv[1];
recedbytes=recv(sockfd,srecv,sizeof(srecv),0);
if(srecv[0]==100)
printf("\nFound");
else if(srecv[0]=-100)
printf("\nNot Found");

for(int i=0;i<5;i++)
{
num[i]==temp[i];
}

}


if(choice[0]==2)
{
for(int i=0;i<5;i++)
{
num[i]==temp[i];
}
int numm[5];
printf("Sorted numbers:");
recedbytes=recv(sockfd,numm,sizeof(numm),0);
for(int i=0;i<5;i++)
printf("%d",numm[i]);
for(int i=0;i<5;i++)
{
num[i]==temp[i];
}

}
else if(choice[0]==3)
{
for(int i=0;i<5;i++)
{
num[i]==temp[i];
}
int nummm[5];
printf("Even numbers followed by odd numbers:");
recedbytes=recv(sockfd,nummm,sizeof(nummm),0);
for(int i=0;i<5;i++)
printf("%d",nummm[i]);
for(int i=0;i<5;i++)
{
num[i]==temp[i];
}
}
printf("\n");
//}

close(sockfd);
}

