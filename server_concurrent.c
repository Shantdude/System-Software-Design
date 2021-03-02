#include"stdio.h"

#include"sys/socket.h"

#include"netinet/in.h"

#include"pthread.h"

#include"string.h"

bbsr()

{

	int nid=*p;//sid=socket id and nid=network id

	char x[100];

	//struct sockaddr_in q;

	//len=sizeof(struct sockaddr_in);

	//sid=ssocket(PF_INET,SOCK_STREAM,IPPROTO_TCP);

	while(1)

	{

		memset(x,0,sizeof(x));//make x[] {0}

		read(nid,x,100);

		printf("%s",x);

		if(strcmp(x,"No")==0)

			pthread_exit(0);

	}		

}

int main()

{

	int sid,nid,len;//sid=socket id and nid=network id

	struct sockaddr_in q;

	pthread_t t1;

	len=sizeof(struct sockaddr_in);

	sid=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP)

		q.sin_family=PF_INET;

		q.sin_port=1500;

		q.sin_addr.s_addr=0;

	bind(sid,&q,len);

	listen(sid,10);

	while(1)

	{

		nid=accept(sid,&q,len);

		pthread_create(&t1,0,(void *)bbsr,(void *)&nid);

	}

	pthread_join(tr1,0);	

}