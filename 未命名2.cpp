#include<stdlib.h>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#if 0

�ж�ѭ������Ϊ���Ļ��������ǣ�rear + 1��% m == front
��front =��rear - length +m��%m
�ۺϵõ��ж�ѭ������Ϊ����������
��rear + 1��% m ==��rear - length + m��%m
#endif
	
#define m 500	

typedef struct{
	int data[m];
	int front;
	int rear;
	
}Seq;
 Seq * sq=(Seq*)malloc(sizeof(Seq));

//�������� 
void Initseq(Seq *&sq)
{
	sq=(Seq*)malloc(sizeof(Seq));
	sq->front=sq->rear=0;
}
//�����ÿ� 
void Setnull(Seq *sq)
{
	sq->front=sq->rear=0;
}
//�󳤶�
 
int Seqlength(Seq *sq)
{
	return (sq->rear-sq->front+m)%m;
}


//���
int Enter(Seq  *sq,int x)
{
	if(sq->front==(sq->rear+1)%m) 
	{
		printf("��������") ;
		return 0;
	} 
	else{
		sq->rear=(sq->rear+1)%m;
		sq->data[sq->rear]=x;
		return 1;
	}
} 
//����

int Out(Seq *sq,int &x) 
{
	if(sq->rear==sq->front)
	{
		printf("��������");
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






