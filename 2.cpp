#include<stdio.h>
int main(int argc,char *argv[],char *envp[])
{
	int i=0;
	while(envp[i])
	printf("\n%s",envp[i++]);
}
