#include"string.h"

#include"stdio.h"

#include"pthread.h"

#include"fcntl.h"

int bbsr(int);

int ctc(int );

int status;

main()

{

	int k=open("eg.txt",O_CREAT|O_APPEND|O_WRONLY);

	pthread_t t1,t2;

	

	pthread_create(&t1,0,(void *)bbsr,(void *)k);

	pthread_create(&t2,0,(void *)ctc,(void *)k);

	

	pthread_join(t1,0);

	pthread_join(t2,0);

	

}

int bbsr(int a)

{

	char x[]="Pratik Is Best";

	pthread_spin_trylock((void *)&status);

	for(int i=0;i<strlen(x);i++)

	{

		write(a,&x[i],1);

		sleep(1);

	}

	pthread_spin_unlock((void *)&status);

}

int ctc(int a)

{

	char x[]="India is the Best";

	pthread_spin_lock((void *)&status);

	for(int i=0;i<strlen(x);i++)

	{

		write(a,&x[i],1);

		sleep(1);

	}

	pthread_spin_unlock((void *)&status);

}