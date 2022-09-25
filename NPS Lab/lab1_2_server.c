#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90
int palindrome(char str[], int n)
{
int i;
for(i=0;i<n/2;i++)
{
if(str[i]!=str[n-i-1])
{printf("String is not a palindrome\n");
return 0;
}
}
printf("String is a palindrome\n");
return 1;
}
int main()
{
	int sockfd,newsockfd,retval,i;
	socklen_t actuallen;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;

	char buff[MAXSIZE];
	int a=0;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	if(sockfd==-1)
	{
		printf("\nSocket creation error");
	}
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3389);
	clientaddr.sin_addr.s_addr=htons(INADDR_ANY);


	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);

	retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==1)
	{
		printf("Binding error");
		close(sockfd);
	}
	
	for (i = 0; ; i+=1)
	{
		
		
		actuallen=sizeof(clientaddr);
		recedbytes=recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&clientaddr,&actuallen);
                
		if(recedbytes==-1)
		{
			printf("Reciving error\n");
			close(sockfd);
		}

		puts(buff);
		
		if (buff[0] == 'H' && buff[1] == 'a' && buff[2] == 'l' && buff[3] == 't')
		{
			break;
		}		

		int n=strlen(buff);
		char temp[n];
		int acount=0,ecount=0,icount=0,ocount=0,ucount=0;
		strcpy(temp,buff);
		int check=palindrome(buff,n);
		if(check==0)
		{
		for(int i=0;i<n;i++)
		buff[i]='N';
		}
		else
		{
		for(int i=0;i<n;i++)
		buff[i]='Y';
		}


		for(int j=0;j<n;j++)
		{
		if(temp[j]=='A'||temp[j]=='a')
		{
		acount++;
		}
		if(temp[j]=='E'||temp[j]=='e') 
                {
                ecount++;
                }
		if(temp[j]=='I'||temp[j]=='i') 
                {
                icount++;
                }
		if(temp[j]=='O'||temp[j]=='o') 
                {
                ocount++;
                }
		if(temp[j]=='U'||temp[j]=='u') 
                {
                ucount++;
                }
		}
int count=acount+ecount+icount+ocount+ucount;
		printf("No. of vowels:%d\n\n",count);
		int cnt[5];
		cnt[0]=acount;
cnt[1]=ecount;
cnt[2]=icount;
cnt[3]=ocount;
cnt[4]=ucount;
		sentbytes=sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
		sentbytes=sendto(sockfd,cnt,sizeof(cnt),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
		if(sentbytes==-1)
		{
			printf("sending error");
			close(sockfd);
		}

		if (buff[0] == 'H' && buff[1] == 'a' && buff[2] == 'l' && buff[3] == 't')
		{
			break;
		}
	}

	

	close(sockfd);
	close(newsockfd);
}

