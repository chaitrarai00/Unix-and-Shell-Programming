#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	struct flock f;
	int fd,n;
	char buf[50];
	if((fd=open(argv[1],O_RDWR))==-1)
	{
		printf("Cant open the file\n");
		exit(0);
	}
	printf("Press Enter to lock the file \n");
	printf("----------------------------\n");

	getchar();
	f.l_type =F_WRLCK;
	f.l_start=0;
	f.l_whence=SEEK_END;
	f.l_len=-100;
	f.l_pid=getpid();
	if((fcntl(fd,F_SETLK,&f))==-1)
	{
		printf("Cant set exclusive lock\n");
		exit(1);
	}
	else if(f.l_type!=F_UNLCK)
	{
		printf("File has been exclusively locked by the process %d\n",f.l_pid);
	}
			
	n=lseek(fd,-50,SEEK_END);
	read(fd,buf,50);
	printf("Last 50 bytes in the file\n");
	printf("-------------------------\n");
	printf("%s\n",buf);
	printf("Press enter to release the lock\n");
	getchar();
	f.l_type =F_UNLCK;
	f.l_start=0;
	f.l_whence=SEEK_END;
	f.l_len=-100;
	if(fcntl(fd,F_SETLK,&f)==0)
	printf("File unlocked successfully\n");
	return 0;
}

