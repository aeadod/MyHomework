#include<stdlib.h>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#if 0

判断循环队列为满的基本条件是（rear + 1）% m == front
而front =（rear - length +m）%m
综合得到判断循环队列为满的条件：
（rear + 1）% m ==（rear - length + m）%m
#endif
	
#define m 500	

typedef struct{
	int data[m];
	int front;
	int rear;
	
}Seq;
 Seq * sq=(Seq*)malloc(sizeof(Seq));

//建立队列 
void Initseq(Seq *&sq)
{
	sq=(Seq*)malloc(sizeof(Seq));
	sq->front=sq->rear=0;
}
//队列置空 
void Setnull(Seq *sq)
{
	sq->front=sq->rear=0;
}
//求长度
 
int Seqlength(Seq *sq)
{
	return (sq->rear-sq->front+m)%m;
}


//入队
int Enter(Seq  *sq,int x)
{
	if(sq->front==(sq->rear+1)%m) 
	{
		printf("队列上溢") ;
		return 0;
	} 
	else{
		sq->rear=(sq->rear+1)%m;
		sq->data[sq->rear]=x;
		return 1;
	}
} 
//出队

int Out(Seq *sq,int &x) 
{
	if(sq->rear==sq->front)
	{
		printf("队列下溢");
		return 0;
	}
	else{
		sq->front=(sq->front+1)%m;
		x=sq->data[sq->front];
		return 1;
	}
}

int main()
{
	Seq * cycque=(Seq*)malloc(sizeof(Seq));
	Initseq(cycque); 
	Setnull(cycque);
	Enter(cycque,1);
	int t;
	Out(cycque,t);
	printf("%d",t);
}






