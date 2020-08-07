#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
int main()
{
int res;
if((res=sysconf(_SC_ARG_MAX))==-1)
printf("error");
else
printf("max length of arguments %d\n",res);
if((res=sysconf(_SC_NGROUPS_MAX))==-1)
printf("error");
else
printf("groups %d\n",res);
if((res=sysconf(_SC_JOB_CONTROL))==-1)
printf("error");
else
printf("xjob control %d\n",res);
if((res=sysconf(_SC_SAVED_IDS))==-1)
printf("error");
else
printf("saved ids %d\n",res);
if((res=sysconf(_SC_TIMERS))==-1)
printf("error");
else
printf("timers %d\n",res);
if((res=sysconf(_SC_RTSIG_MAX))==-1)
printf("error");
else
printf("real time %d\n",res);
if((res=sysconf(_SC_SEM_NSEMS_MAX))==-1)
printf("error");
else
printf("sem %d\n",res);
if((res=sysconf(_SC_AIO_MAX))==-1)
printf("error");
else
printf("asynchrome %d\n",res);
if((res=pathconf("/",_PC_CHOWN_RESTRICTED))==-1)
printf("error");
else
printf("chown %d\n",res);
if((res=pathconf("/",_PC_NO_TRUNC))==-1)
printf("error");
else
printf("trunc %d\n",res);
if((res=pathconf("/",_PC_VDISABLE))==-1)
printf("error");
else
printf("vdisable %d\n",res);
if((res=pathconf("/",_PC_LINK_MAX))==-1)
printf("error");
else
printf("link %d\n",res);
if((res=pathconf("/",_PC_PIPE_BUF))==-1)
printf("error");
else
printf("pipe %d\n",res);
if((res=pathconf("/",_PC_MAX_INPUT))==-1)
printf("error");
else
printf("max input  %d\n",res);
return 0;
}


