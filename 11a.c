#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int parsecondition(char[],int,char *,int);
void gen(char[],char[],char[],int);
int main()
{
int stlen=0,counter=0,elseflag=0;
char stmt[60],strB[60],strS1[60],strS2[60];
printf("\nformat of if statement:..........");
printf(".......................................................................................");
printf("\nif(a<b)then(s,a);");
printf("\nif(a<b)then(s,a)else(s,b);");
printf("\nenter statement:\n");
scanf("%s",stmt);
stlen=strlen(stmt);
counter=counter+2;
counter=parsecondition(stmt,counter,strB,stlen);
if(stmt[counter]==')')
counter++;
counter=counter+3;
counter=parsecondition(stmt,counter,strS1,stlen);
if(stmt[counter+1]==';')
{
printf("\nparsing the input:");
gen(strB,strS1,strS2,elseflag);
return 0;
}
if(stmt[counter]==')')
counter++;
counter=counter+3;
counter=parsecondition(stmt,counter,strS2,stlen);
counter=counter+2;
if(counter==stlen)
{
elseflag=1;
printf("\nparsing the input:");
gen(strB,strS1,strS2,elseflag);
return 0;
}
return 0;
}

int parsecondition(char input[],int cntr,char *dest,int totallen)
{
int index=0,pos=0;
while(input[cntr]!='(' && cntr<=totallen)
cntr++;
if(cntr>=totallen)
return 0;
index=cntr;
while(input[cntr]!=')')
cntr++;
if(cntr>=totallen)
return 0;
while(index<=totallen)
dest[pos++]=input[index++];
dest[pos]='\0';
return cntr;
}

void gen(char B[],char S1[],char S2[],int elsepart)
{
int bt=101,bf=102,sn=103;
printf("\n\tif %s then %d",B,bt);
printf("\n\tgoto %d",bf);
printf("\n\t%d:",bt);
printf("%s",S1);
if(!elsepart)
printf("\n\t%d:",bf);
else
{
printf("\n\tgoto %d",sn);
printf("\n\t%d:",bf);
printf("%s",S2);
printf("\n\t%d:",sn);
}
}
