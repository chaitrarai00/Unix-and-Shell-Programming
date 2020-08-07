#define _POSIX_SOURCE
#define _POXSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>

int main()
{
#ifdef _POSIX_JOB_CONTROL
printf("System supports job control\n");
#else
printf("system does not support job control\n");
#endif

#ifdef _POSIX_SAVED_IDS
printf("system support saved ids\n");
#else
printf("System does not support saved ids\n");
#endif

#ifdef _POSIX_CHOWN_RESTRICTED
printf("system support chown Restricted\n");
#else
printf("System does not support chown Restricted\n");
#endif

#ifdef _POSIX_NO_TRUNC
printf("system support no_trunc\n");
#else
printf("System does not support no_trunc\n");
#endif

#ifdef _POSIX_VDISABLE
printf("system support vdisable\n");
#else
printf("System does not support vdisable\n");
#endif

return 0;

}








