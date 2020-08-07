#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		printf("First child created is %d\n",getpid());
		exit(0);
	}
	else
	{
		sleep(3);
		printf("This is the Parent process %d\n",getpid());
		system("ps -c -o pid,ppid,stat,cmd");
	}
	return 0;	
	
}
