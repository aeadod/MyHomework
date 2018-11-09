#include<stdlib.h>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<string.h>

void StrInsert(char * S,char * T,int i)
{
char temp[100];
for(int j=0;j<100;j++)
{
	temp[j]=0;
}
strcpy(temp,S+i-1);
strcpy(S+i-1,T);
strcat(S,temp);
}
int  main()
{
char src[100]="abcdef";
char dest[100]="123456";
int loca=0;
printf("Please input the location:");
scanf("%d",&loca);
if(loca>strlen(src))
{
	printf("请插入到正确的位置。");
}
else{

StrInsert(src,dest,loca);
printf("New src is:%s\n",src);

}

return 0;
}



