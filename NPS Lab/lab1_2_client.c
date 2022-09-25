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
	int sockfd,retval,i;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr, clientaddr;
	char buff[MAXSIZE];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\nSocket Creation Error");
		close(sockfd);

	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3389);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	retval=bind(sockfd,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
	if(retval==1)
	{
		printf("Binding error");
		close(sockfd);
	}

	for (i = 0; ; i+= 1)
	{
		
		
		printf("enter the text\n");
		scanf("%s",buff);

		sentbytes=sendto(sockfd,buff,sizeof(buff),0,
		(struct sockaddr*)&serveraddr,sizeof(serveraddr));

		if(sentbytes==-1)
		{
		printf("sending error");
		close(sockfd);
		}
		
		if (buff[0] == 'H' && buff[1] == 'a' && buff[2] == 'l' && buff[3] == 't')
		{
			break;
		}
	
		int size=sizeof(serveraddr);
int cnt[5];
		recedbytes=recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&serveraddr,&size);
recedbytes=recvfrom(sockfd,cnt,sizeof(cnt),0,(struct sockaddr*)&serveraddr,&size);
		
//puts(buff);
if(buff[0]=='Y')
printf("Palindrome\n");
else if(buff[0]=='N')
printf("Not a palindrome\n");
printf("Vowel count:\n[A|a    E|e    I|i    O|o    U|u]\n");
for(int k=0;k<5;k++)
{
printf("%d",cnt[k]);
printf("\t");
}
		printf("\n\n");

		if (buff[0] == 'H' && buff[1] == 'a' && buff[2] == 'l' && buff[3] == 't')
		{
			break;
		}
		
	}
	
	close(sockfd);
}
