#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#define MAXSIZE 90
main()
{       //variables declaration and initialization
	int sockfd,newsockfd,retval,i;
	socklen_t actuallen;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;
	char buff[MAXSIZE];
	char msg1[MAXSIZE]="Found";
	char msg[MAXSIZE]="Not Found";
	int a=0;
        //socket creation
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
	printf("\nSocket creation error");
	}
        //socket attributes initialization
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
        //socket binding
	retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==1)
	{
		printf("Binding error");
		close(sockfd);
	}
	//listen
	retval=listen(sockfd,1);
	if(retval==-1)
	{
	close(sockfd);

	}
	//accept
	actuallen=sizeof(clientaddr);
	newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);
	if(newsockfd==-1)
	{
		close(sockfd);
	}
	//read file name
	memset(buff, '\0', sizeof(buff));
        recedbytes=recv(newsockfd,buff,sizeof(buff),0);
        if(recedbytes==-1)
        {
                close(sockfd);
                close(newsockfd);
        }
	printf("The filename:"); 
        printf("%s \n",buff);
//if file is there, send found
FILE *file;
    
    if (file = fopen(buff, "r")) 
    {
                     msg1[strlen(msg1)] = '\0';
                int s = strlen(msg1) * sizeof(char);
                sentbytes=send(newsockfd,msg1,s,0);

    }
//else send not found
    else
    {
                msg[strlen(msg)] = '\0';
                int s = strlen(msg) * sizeof(char);
                sentbytes=send(newsockfd,msg,s,0);
    }	
	close(sockfd);
	close(newsockfd);
}


