#include"stdio.h"

int bbsr()
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("I am in bbsr\n");
		sleep(1);
	}
}

int ctc()
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("I am in ctc\n");
		sleep(1);
	}
}

main()

{

	int k=fork();
	if(k==0)
		bbsr();
	else
		ctc();
}
