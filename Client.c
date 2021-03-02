#include<stdio.h>

#include<sys/socket.h>

#include<netinet/in.h>

struct inadder

{
	int s_addr;
};

struct sockaddr_n
{
	int sin_family;

	short int sin_port;

	struct inadder sin_addr;
}

main()
{
	int sid,len,nid,status;

	struct sockaddr_n q;

	char x[100];

	len=sizeof(struct sockaddr_n);

	sid=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);

		q.sin_family=PF_INET;

		q.sin_port=1500;

		q.sin_addr.s_addr=0;

	status=connect(sid, &q,len);

	if(status==-1)
	{
		printf("Connection Error\n");

		return ;
	}

	printf("Enter the message:");

	scanf("%s", x);

	write(sid,x,strlen(x));
}
