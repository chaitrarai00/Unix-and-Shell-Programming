#include<stdio.h>
#include<unistd.h>
int main (int argc,char *argv[])
{
if(argc<3||argc>4)
{
printf("usage: %s[-s]<src-file><dest-file>\n",argv[0]);
return 1;
}
if(argc==4)
return symlink(argv[2],argv[3]);
else
return link(argv[1],argv[2]);
}

