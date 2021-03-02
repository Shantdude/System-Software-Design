#include<stdio.h>

#include<fcntl.h>

#include<string.h>

main()

{

	int k=open("letter.txt", O_WRONLY|O_APPEND|O_CREAT);

	char x[]="Madarchod";

	int i;

	flock(k,LOCK_EX);

	for(i=0;i<strlen(x);i++)

	{

		write(k,&x[i],1);

		sleep(1);

	}

	flock(k,LOCK_UN);

}	
