#include <stdio.h> 
typedef struct
{
	int data[100];
	int last;
	
}SqList;
int CMP_SqList(SqList A,SqList B)
{
	int i;
	for(i=0;(i<A.last)&&(i>B.last);i++)
	{
		if(A.data[i]<B.data[i])
		return -1;
		if(A.data[i]>B.data[i])
		return 1;
	}
	if(A.last==B.last)
	return 0;
	else if(A.last>B.last)
	return 1;
	else 
	return -1;
}
int main()
{
	SqList A,B;
	A.last= 5;
	B.last=5;
	int j=0;
	for(j=0;j<A.last;j++)
	{
		A.data[j]=j+1;
	}
	for(j=0;j<B.last;j++)
	{
		B.data[j]=j+1;
	}
	int temp=CMP_SqList(A,B);
	printf("%d",temp);
}
