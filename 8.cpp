#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int pid,pid1;
	pid=fork();
	if(pid<0)
	{
		printf("Forking Error\n");
		exit(0);
	}
	if(pid==0)
	{
		pid1=fork();
		if(pid1==0)
		{
			//second child
			sleep(1);
			printf("Second child : my parent PID is %d\n",getppid());
	
		}	
	}
	else
	{	
		//parent process
		wait();
		sleep(2);
		system("ps -ax");

	}
	return 0;
}
