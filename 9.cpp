#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#define INTERVAL 5
int i=1;
void wakeup(int sig_no)
{
	alarm(INTERVAL);
	printf("Catch Signal\n");
}

int main()
{
	struct sigaction action;
	action.sa_handler=wakeup;
	action.sa_flags=SA_RESTART;
	sigemptyset(&action.sa_mask);
	if(sigaction(SIGALRM,&action,0)==-1)
	{
		perror("sigaction");
	}
	if(alarm(INTERVAL)==-1)
	perror("Alarm");
	else while(1)
	{
		//printf("Do normal operation \n");
		
		printf("%d\n",i++);	
		sleep(1);
	}	
	return 0;
}
