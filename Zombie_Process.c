//Zombie process//

#include<stdio.h>
main()
{
	int i;
	int k=fork();
	if(k==0)
	{
		for(i=0;i<5;i++)
		{
			printf("Child process\n");
               		sleep(1);
		}	

	}
	else
	{
		for(i=0;i<10;i++)

		{
			printf("Paraent Process\n");
			sleep(1);
		}

	}
}


