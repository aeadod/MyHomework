#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<iostream>
void  saddle(int A[3][3],int m,int n)
{	int i,j,p=0,q=0,min,max;
	for(i=0;i<m;i++) /*���д���*/
	{
		min=A[i][0];
	for(j=1;j<n;j++)
	{
		if(A[i][j]<min) /*�ҵ�i����Сֵ*/
		{
			min=A[i][j];
			p=j;
        }
    }
    max=A[0][p];
    for(j=0;j<m;j++){
    	if(A[j][p]>max)
    	{
    		max=A[j][p];
    		q=j;
    	}
    }
    if(q==i){
    	printf("%d�����㡣\n",A[q][p]);
    }
}
}
int main()
{
	int A[3][3]={{1,7,3},{5,4,6},{17,18,9}};
	saddle(A,3,3);
	return 0;
}
