#include<stdio.h> 
typedef int ElemType;   
typedef struct
{
    ElemType elem[100]; 
    int length;     
    int listsize;   
}SqList;
void ReverseList(SqList*L)
{
    int i,temp;
    int n=L->length;

    for(i=0;i<n/2;i++)
    {
        temp=L->elem[i];
        L->elem[i]=L->elem[n-1-i];
        L->elem[n-1-i]=temp;
    }
}
int main()
{
	SqList A;
	SqList* L;
	L=&A;
	int j,h;
	A.length=5;
	for(j=0;j<A.length;j++)
	{
		A.elem[j]=j+1;
	}
	ReverseList(L);
	for(h=0;h<A.length;h++)
	{
		printf("%5d",A.elem[h]);
	}
	
}
