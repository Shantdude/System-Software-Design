#include"string.h"

#include"stdio.h"

#include"pthread.h"

#include"fcntl.h"

#include"sys/sem.h"

#include"sys/ipc.h"

int bbsr(int);

int ctc(int );

int sid;

struct sembuf p={0,-15,SEM_UNDO};//{semaphore number, operation,undo}

struct sembuf q={0,15,SEM_UNDO};//{semaphore number, operation,undo}

main()

{

	int k=open("eg.txt",O_CREAT|O_APPEND|O_WRONLY);

	pthread_t t1,t2;

	

	sid=semget(100,1,IPC_CREAT);//create a semaphore (man semget() for more info)

	semctl(sid,0,SETVAL,15);//initialize a semaphore

	

	pthread_create(&t1,0,(void *)bbsr,(void *)k);

	pthread_create(&t2,0,(void *)ctc,(void *)k);

	

	pthread_join(t1,0);

	pthread_join(t2,0);

	

}

int bbsr(int a)

{

	char x[]="Pratik Is Best";

	semop(sid,&p,1);

	for(int i=0;i<strlen(x);i++)

	{

		write(a,&x[i],1);

		sleep(1);

	}

	semop(sid,&q,1);

}

int ctc(int a)

{

	char x[]="India is the Best";

	semop(sid,&p,1);

	for(int i=0;i<strlen(x);i++)

	{

		write(a,&x[i],1);

		sleep(1);

	}

	semop(sid,&q,1);

}