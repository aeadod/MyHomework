#include<stdio.h>
#include<malloc.h> 

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
LinkList Init_LNode()
{
	LNode *L;
	L=(LinkList)malloc(sizeof(LNode));
	if(L==NULL)
	{
		printf("��ʼ��ʧ�ܣ�");
		
	}
	L->next=NULL;
	return L;
}
void Creat_List(LNode *L)
{
	int i,n,num;
	LNode *p,*pnew;
	p=L;
	printf("������Ҫ�����Ԫ�ظ�����n=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("�������%d������",i+1);
		scanf("%d",&num);
		pnew=(LinkList)malloc(sizeof(LNode));
		if(pnew == NULL)
		{
			printf("��ʼ��ʧ��!\n");		
		}
		pnew->data = num;
		p->next = pnew;
		p = pnew;
	}
	p->next =NULL;
}






void InsertInOrder (LNode *L,int x)
//��ֵΪx���½ڵ���뵽����ͷ���ķǵݼ�����������
{
	LNode *s=NULL;
	LNode *p=NULL;
	LNode *q=NULL;
	LNode *head=L;
	s=(LinkList)malloc(sizeof(LNode));
	//����һ��������Ľڵ�
	s->data=x;
	s->next=NULL;
	p=head->next;
	q=head;
	while(((p!=NULL)&&(x>(p->data))))
	{
		q=p;
		p=p->next;
	}
	if(p==NULL)
	{
		q->next=s;
	}
	else
	{
		s->next=p;
		q->next=s;
	}
}
int main()
{
	LinkList S;
    S = Init_LNode();
    Creat_List(S);
    InsertInOrder (S,3);
	while(S->next)
	{ 
		printf("%d ",S->next->data);
		S = S->next;
	}
}



