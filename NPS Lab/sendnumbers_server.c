//SERVER

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90

void bubble_sort(int list[], int n)
{
    int c, d, t;
 
    for (c = 0; c < (n - 1); c++) {
        for (d = 0; d < n - c - 1; d++) {
            if (list[d] > list[d + 1]) {
 
                /* Swapping */
                t = list[d];
                list[d] = list[d + 1];
                list[d + 1] = t;
            }
        }
    }
}


int main()
{
int sockfd,newsockfd,retval;
socklen_t actuallen;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;

int numser[MAXSIZE];
int a=0;
sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1)
{
printf("\nSocket creation error");
}

serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==1)
{
printf("Binding error");
close(sockfd);
}

retval=listen(sockfd,1);
if(retval==-1)
{
close(sockfd);
}

actuallen=sizeof(clientaddr);
newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);


if(newsockfd==-1)
{
close(sockfd);
}
recedbytes=recv(newsockfd,numser,sizeof(numser),0);

if(recedbytes==-1)
{
close(sockfd);
close(newsockfd);
}
printf("The received numbers at server are:");
for(int j=0;j<5;j++)
printf("%d",numser[j]);

printf("\n");
int choice;
recv(newsockfd,choice,sizeof(choice),0);
if(choice==1)
{
}
else if(choice==2)
{
bubble_sort(numser,5);
printf("The sorted numbers:");
for(int m=0;m<5;m++)
printf("%d",numser[m]);

}
else if(choice==3)
{
int odd[5],even[5];int evenidx=0,oddidx=0;
for(int n=0;n<5;n++)
{
if(numser[n]%2==0)
{
even[evenidx]=numser[n];
evenidx++;
}
else
{odd[oddidx]=numser[n];
oddidx++;

}
}
printf("Even are:");
for(int e=0;e<evenidx;e++)
printf("%d ",even[e]);
printf("Odd are:");
for(int o=0;o<oddidx;o++)
printf("%d ",odd[o]);


}

if(sentbytes==-1)
{
close(sockfd);
close(newsockfd);
}

close(sockfd);
close(newsockfd);
}

