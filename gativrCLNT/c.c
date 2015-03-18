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
 main( )
{
	int socket_desc;
FILE *f9,*f2,*f3,*f4,*f5,*f6,*f7,*f8,*fp11,*fp0,*fp20,*fp21,*fp22,*fp23;

char a1[160],c;
char ll[]="fe80::beae:c5ff:fed8:a5c4";
int i,n,i1,k,m,t,l,x,in,in1,bindre;
struct rtp_message msg;
struct sockaddr_in6 serv,iserv;
struct hostent *hp;
fp0 = fopen("speech13.pcm","w");
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
inet_pton(AF_INET6,ll, &(serv.sin6_addr));serv.sin6_scope_id =if_nametoindex("eth1");
//bind
bzero((char *) &iserv,sizeof iserv);
iserv.sin6_family=AF_INET6;
//iserv.sin6_addr.s6_addr=htonl(INADDR_ANY);
iserv.sin6_addr=in6addr_any;
iserv.sin6_port=htons(0);
bindre=bind(socket_desc,( struct sockaddr *)&iserv,sizeof(iserv));
printf("bind %d\n",bindre);
n=sendto(socket_desc,(char *)&in,4,0,(struct sockaddr *) &serv,sizeof iserv);
printf("sent %d\n",n);
for(m=0;m<8;m++)
{
printf("byte %d byte val %c \n",m,a[m]);
}
for(t=0;t<389;t++)
{
i1=sizeof iserv;
k=recvfrom (socket_desc,(char *)&msg,200,0,(struct sockaddr *)&serv,&i1);
//printf("recvd %d\n",k);
for(l=0;l<160;l++)
{
fputc(msg.sample[l],fp0); 
}
}
fclose(fp0);
fp0=fopen("media11.hdr","r");
fp11=fopen("speech13.pcm","r");
fp20=fopen("voice.pcm","w");
for (i=0; i <44; i++)
{  c= fgetc(fp0);
   fputc(c,fp20);
} 
fclose(fp0);
 for (i=0; i <62206; i++)
{  c= fgetc(fp11);
   fputc(c,fp20);
} 
fclose(fp11);
fclose(fp20);
system("aplay voice.pcm");
system("rm speech13.pcm");
system("rm voice.pcm");

while(1)
{
printf("enter the digit\n");
scanf("%d",&in);
in1=in;
in=in<<24;
if (in1==1)
{
f2 = fopen("speech14.pcm","w");
n=sendto(socket_desc,(char *)&in,4,0,(struct sockaddr *) &serv,sizeof iserv);
//printf("sent %d\n",n);
for(t=0;t<167;t++)
{
i1=sizeof iserv;
k=recvfrom (socket_desc,(char *)&msg,200,0,(struct sockaddr *)&serv,&i1);
//printf("recvd %d\n",k);
for(l=0;l<160;l++)
{
fputc(msg.sample[l],f2); 
}
}
fclose(f2);
f2=fopen("media7.hdr","r");
f3=fopen("speech14.pcm","r");
fp21=fopen("voice1.pcm","w");
for (i=0; i <44; i++)
{  c= fgetc(f2);
   fputc(c,fp21);
} 
fclose(f2);
 for (i=0; i <26778; i++)
{  c= fgetc(f3);
   fputc(c,fp21);
} 
fclose(f3);
fclose(fp21);
system("aplay voice1.pcm");
system("rm speech14.pcm");
system("rm voice1.pcm");
}
if (in1==2)
{
f4 = fopen("speech15.pcm","w");
n=sendto(socket_desc,(char *)&in,4,0,(struct sockaddr *) &serv,sizeof iserv);
//printf("sent %d\n",n);
for(t=0;t<162;t++)
{
i1=sizeof iserv;
k=recvfrom (socket_desc,(char *)&msg,200,0,(struct sockaddr *)&serv,&i1);
//printf("recvd %d\n",k);
for(l=0;l<160;l++)
{
fputc(msg.sample[l],f4); 
}
}
fclose(f4);
f4=fopen("media6.hdr","r");
f5=fopen("speech15.pcm","r");
fp22=fopen("voice2.pcm","w");
for (i=0; i <44; i++)
{  c= fgetc(f4);
   fputc(c,fp22);
} 
fclose(f4);
 for (i=0; i <26016; i++)
{  c= fgetc(f5);
   fputc(c,fp22);
} 
fclose(f5);
fclose(fp22);
system("aplay  voice2.pcm");
system("rm speech15.pcm");
system("rm voice2.pcm");

}
if (in1>=3)
{
f6 = fopen("speech16.pcm","w");
n=sendto(socket_desc,(char *)&in,4,0,(struct sockaddr *) &serv,sizeof iserv);
//printf("sent %d\n",n);
for(t=0;t<99;t++)
{
i1=sizeof iserv;
k=recvfrom (socket_desc,(char *)&msg,200,0,(struct sockaddr *)&serv,&i1);
//printf("recvd %d\n",k);
for(l=0;l<160;l++)
{
fputc(msg.sample[l],f6); 
}
}
fclose(f6);
f6=fopen("media5.hdr","r");
f7=fopen("speech16.pcm","r");
fp23=fopen("voice3.pcm","w");
for (i=0; i <44; i++)
{  c= fgetc(f6);
   fputc(c,fp23);
} 
fclose(f6);
 for (i=0; i <15846; i++)
{  c= fgetc(f7);
   fputc(c,fp23);
} 
fclose(f7);
fclose(fp23);
system("aplay  voice3.pcm");
system("rm speech16.pcm");
system("rm voice3.pcm");
}
}
close(socket_desc);
exit(0);
}	

