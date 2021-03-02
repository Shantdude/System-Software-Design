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

	int sid,len,nid;

	struct sockaddr_n q;

	char x[100];

	len=sizeof(struct sockaddr_n);

	sid=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);

		q.sin_family=0;

		q.sin_port=0;

		q.sin_addr.s_addr=0;

	bind(sid,&q,len);

	listen(sid, 10);

	while(1)

	{

		memset(x,0,sizeof(x));

		nid=accept(sid,&q,&len);

		read(nid,x,100);

		printf("%s",x);

		

	}

}
