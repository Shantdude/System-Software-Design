#include"stdio.h"

//#include"pthread.h"

int bbsr()

{

	int i;

	for(i=0;i<5;i++)

	{

		printf("I'm IN BBSR\n");

		sleep(1);//Execute at 1 sec interval

	}

}

int ctc()

{

	int i;

	for(i=0;i<5;i++)

	{

		printf("I'm IN CTC\n");

		sleep(1);//Execute at 1 sec interval

	}

}

int main()

{

	int k;

	k=fork();

	if(k==0)

		bbsr();

	else

		ctc();

}

