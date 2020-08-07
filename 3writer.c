#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
int fd;
char *myfifo="/tmp/myfifo";
mkfifo(myfifo,0666);
printf("run reader process to read fifo\n");
fd=open(myfifo,O_WRONLY);
write(fd,"hi",sizeof("hi"));
close(fd);
unlink(myfifo);
return 0;
}


