#include<stdio.h>
 #include <sys/types.h>       
 #include <sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#define SPORT 60020
 char a[8]={'8','2','3','4','5','6','7','1'};
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
FILE *f9,*f2,*f3,*f4,*f5,*f6,*f7,*f8,*f11,*f0;
f2 = fopen("speech1.pcm","w");
f4 = fopen("speech2.pcm","w");
f6 = fopen("speech3.pcm","w");
f8 = fopen("speech4.pcm","w");
f0=fopen("speech12.pcm","w");
char a1[160],c;
int i,n,i1,k,m,t,l,x,in,in1,bindre;
struct rtp_message msg;
struct sockaddr_in6 serv,iserv;
struct hostent *hp;
	socket_desc=socket(AF_INET6,SOCK_DGRAM,0);
	printf("Sock desc= %d\n",socket_desc);
	if(socket_desc==-1)
	{
		printf("could not create socket");
	}
	//return 0;
serv.sin6_family=AF_INET6;
//serv.sin6_addr.s6_addr=inet6_addr(IPA);
serv.sin6_port=htons(SPORT);
inet_pton(AF_INET6,"::1", &(serv.sin6_addr));
//bind
bzero((char *) &iserv,sizeof iserv);
iserv.sin6_family=AF_INET6;
//iserv.sin6_addr.s6_addr=htonl(INADDR_ANY);
iserv.sin6_addr=in6addr_any;
iserv.sin6_port=htons(0);
bindre=bind(socket_desc,( struct sockaddr *)&iserv,sizeof(iserv));
printf("bind %d\n",bindre);
n=sendto(socket_desc,(char *)&in,4,0,(struct sockaddr *) &serv,sizeof serv);
printf("sent %d\n",n);
for(m=0;m<8;m++)
{
printf("byte %d byte val %c \n",m,a[m]);
}
for(t=0;t<189;t++)
{

i1=sizeof iserv;
k=recvfrom (socket_desc,(char *)&msg,200,0,(struct sockaddr *)&iserv,&i1);
printf("recvd %d\n",k);

for(l=0;l<160;l++)
fputc(msg.sample[l],f0); 
}
fclose(f0);
f0=fopen("media11.hdr","a");
f11=fopen("speech12.pcm","r");
while((c=getc(f11))!=EOF)
{
fputc(c,f0);
//printf("%c",c);
}
fclose(f11);
fclose(f0);

system("aplay media11.hdr");


while(1)
{
printf("enter the digit");
scanf("%d",&in);
in1=in;
in=in<<24;
if (in1==3)
{
n=sendto(socket_desc,(char *)&in,4,0,(struct sockaddr *) &serv,sizeof serv);
printf("sent %d\n",n);
for(t=0;t<189;t++)
{
i1=sizeof iserv;
k=recvfrom (socket_desc,(char *)&msg,200,0,(struct sockaddr *)&iserv,&i1);
printf("recvd %d\n",k);
for(l=0;l<160;l++)
fputc(msg.sample[l],f2); 
}
fclose(f2);
f2=fopen("media7.hdr","a");
f3=fopen("speech1.pcm","r");
while((c=getc(f3))!=EOF)
{
fputc(c,f2);
printf("%c",c);
}
fclose(f3);
fclose(f2);
}
system("aplay media7.hdr");
if (in1==4)
{
n=sendto(socket_desc,(char *)&in,4,0,(struct sockaddr *) &serv,sizeof serv);
printf("sent %d\n",n);
for(t=0;t<189;t++)
{
i1=sizeof iserv;
k=recvfrom (socket_desc,(char *)&msg,200,0,(struct sockaddr *)&iserv,&i1);
printf("recvd %d\n",k);
for(l=0;l<160;l++)
fputc(msg.sample[l],f4); 
}
fclose(f4);
f4=fopen("media6.hdr","a");
f5=fopen("speech2.pcm","r");
while((c=getc(f5))!=EOF)
{
fputc(c,f4);
printf("%c",c);
}
fclose(f5);
fclose(f4);
}
system("aplay media6.hdr");
if (in1==5)
{
n=sendto(socket_desc,(char *)&in,4,0,(struct sockaddr *) &serv,sizeof serv);
printf("sent %d\n",n);
for(t=0;t<189;t++)
{
i1=sizeof iserv;
k=recvfrom (socket_desc,(char *)&msg,200,0,(struct sockaddr *)&iserv,&i1);
printf("recvd %d\n",k);
for(l=0;l<160;l++)
fputc(msg.sample[l],f6); 
}
fclose(f6);
f6=fopen("media7.hdr","a");
f7=fopen("speech3.pcm","r");
while((c=getc(f7))!=EOF)
{
fputc(c,f6);
printf("%c",c);
}
fclose(f6);
fclose(f7);
}
system("aplay media7.hdr");

if (in1==6)
{
n=sendto(socket_desc,(char *)&in,4,0,(struct sockaddr *) &serv,sizeof serv);
printf("sent %d\n",n);
for(t=0;t<189;t++)
{
i1=sizeof iserv;
k=recvfrom (socket_desc,(char *)&msg,200,0,(struct sockaddr *)&iserv,&i1);
printf("recvd %d\n",k);
for(l=0;l<160;l++)
fputc(msg.sample[l],f8); 
}
fclose(f8);
f8=fopen("media8.hdr","a");
f9=fopen("speech4.pcm","r");
while((c=getc(f9))!=EOF)
{
fputc(c,f8);
printf("%c",c);
}
fclose(f8);
fclose(f9);
}
system("aplay media8.hdr");
}
close(socket_desc);
exit(0);
}	

