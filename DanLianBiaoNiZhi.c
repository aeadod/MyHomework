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
LNode* ReverseList(LNode*head)
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	LNode*rev=NULL;
	LNode*cur=head;
	while(cur!=NULL)
	{
		LNode*temp=cur;
		cur=cur->next;
		temp->next=rev;
		rev=temp;
	}
	return rev;
}

int main()
{
	LinkList S;
    S = Init_LNode();
    Creat_List(S);
    LNode* now=ReverseList(S);
	while(now->next)
	{ 
		printf("%5d",now->data);
		now = now->next;
	}	
}
