#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
static void charatatime(char*str)
{
	char *ptr;
	int c;
	setbuf(stdout,NULL);
	for(ptr=str;(c=*ptr++)!=0; )
	putc(c,stdout);
	sleep(1);
}
int main(void)
{
	pid_t pid;
	if((pid=fork())<0)
	{
		printf("Fork Error");
	}
	else if(pid == 0)
	{
		charatatime("Output from child \n");
	}
	else
	{
	charatatime("Output from Parent \n");
	}	
	exit(0);
}


