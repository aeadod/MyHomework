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
		printf("初始化失败！");
		
	}
	L->next=NULL;
	return L;
}
void Creat_List(LNode *L)
{
	int i,n,num;
	LNode *p,*pnew;
	p=L;
	printf("请输入要输入的元素个数：n=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个数：",i+1);
		scanf("%d",&num);
		pnew=(LinkList)malloc(sizeof(LNode));
		if(pnew == NULL)
		{
			printf("初始化失败!\n");		
		}
		pnew->data = num;
		p->next = pnew;
		p = pnew;
	}
	p->next =NULL;
}






void InsertInOrder (LNode *L,int x)
//将值为x的新节点插入到带有头结点的非递减有序单链表中
{
	LNode *s=NULL;
	LNode *p=NULL;
	LNode *q=NULL;
	LNode *head=L;
	s=(LinkList)malloc(sizeof(LNode));
	//生成一个待插入的节点
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



