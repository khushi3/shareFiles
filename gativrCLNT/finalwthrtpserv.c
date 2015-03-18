#include<stdio.h>
 #include <sys/types.h>       
 #include <sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#define SPORT 60020
 char a[160],a1[160];
FILE *f1,*f2,*f3,*f4,*f5;
struct header_info {
short int vpecmp;
short int seq_no;
int time_stamp;
int ssrc; 

};

struct rtp_message
{
struct header_info x;
char sample[160];
};
int main(int argc,char *argv[])
{
	int socket_desc;
int i,n,i1,k,m,l,in,bindre;char c;
	struct sockaddr_in6 serv,iserv;
struct rtp_message msg;
	struct hostent *hp;
	socket_desc=socket(AF_INET6,SOCK_DGRAM,0);
	printf("Sock desc= %d\n",socket_desc);
bzero((char *) &serv,sizeof serv);
//serv.sin6_addr.s_addr=inet_addr(IPA);
iserv.sin6_family=AF_INET6;
iserv.sin6_port=htons(SPORT);
inet_pton(AF_INET6,"::1", &(iserv.sin6_addr));


bindre=bind(socket_desc,( struct sockaddr *)&iserv,sizeof(iserv));
printf("Bind re=%d\n",bindre);
i1=sizeof iserv;
k=recvfrom (socket_desc,a1,8,0,(struct sockaddr *)&iserv,&i1);
printf("recvd %c\n",k);
for(m=0;m<8;m++)
{
	printf("byte%d byte val %c \n",m,a1[m]);

}
f5=fopen("speech11.pcm","r");
for(m=0;m<189;m++)
{
for(l=0;l<160;l++)
 {
c=fgetc(f5);
msg.sample[l]=c;
}
n=sendto(socket_desc,&msg,sizeof(struct rtp_message),0,(struct sockaddr *) &iserv,sizeof serv);
}
//printf("sent %d\n",n);

	while(1)
	{
i1=sizeof iserv;
k=recvfrom (socket_desc,(char *)&in,4,0,(struct sockaddr *)&iserv,&i1);
printf("recvd%x\n",in);
printf(" received digit is= %d\n",in);
in=in>>24;
if (in==3)
{
f1=fopen("speech5.pcm","r");
for(m=0;m<189;m++)
{
	for(l=0;l<160;l++)
 	{
	c=fgetc(f1);
	msg.sample[l]=c;
	}
n=sendto(socket_desc,&msg,sizeof(struct rtp_message),0,(struct sockaddr *) &iserv,sizeof serv);
}
printf("sent %d\n",n);
}
	if (in==4)
{
	f2=fopen("speech6.pcm","r");
for(m=0;m<189;m++)
{
for(l=0;l<160;l++)
 {
c=fgetc(f2);
msg.sample[l]=c;
}
n=sendto(socket_desc,&msg,sizeof(struct rtp_message),0,(struct sockaddr *) &iserv,sizeof serv);
}
printf("sent %d\n",n);
}
if (in==5)
{
f3=fopen("speech7.pcm","r");
for(m=0;m<189;m++)
{
	for(l=0;l<160;l++)
 	{
	c=fgetc(f3);
	msg.sample[l]=c;
	}
n=sendto(socket_desc,&msg,sizeof(struct rtp_message),0,(struct sockaddr *) &iserv,sizeof serv);
}
printf("sent %d\n",n);
}
if (in==6)
{
f4=fopen("speech8.pcm","r");
for(m=0;m<189;m++)
{
	for(l=0;l<160;l++)
 	{
	c=fgetc(f4);
	msg.sample[l]=c;
	}
n=sendto(socket_desc,&msg,sizeof(struct rtp_message),0,(struct sockaddr *) &iserv,sizeof serv);
}
printf("sent %d\n",n);
}
}
/*for(m=0;m<8;m++)
{
printf("byte %d byte val %c \n",m,a[m]);
}*/
close(socket_desc);
exit(0);
}


