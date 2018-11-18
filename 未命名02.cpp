#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024
typedef int datatype;
typedef struct node {
	datatype data;
	struct node * lchild;
	struct node * rchild;
	int ltag ,rtag;
}bithrnode;

void inthreading(bithrnode *p)
{
	bithrnode *pre=NULL;
	if(p!=NULL)
	{
		inthreading(p->lchild);
		if(p->lchild==NULL){
			p->ltag=1;
			p->lchild=pre;
		}
		if(p->rchild==NULL) p->rtag=1;
		if(pre!=NULL&&pre->rtag==1) pre->rchild=p;
		pre=p;
		inthreading(p->rchild);	
	}	
}
void prethreading(bithrnode *p)
{
	bithrnode *pre=NULL;
	if(p!=NULL)
	{
		inthreading(p->lchild);
		if(p->lchild==NULL){
			p->ltag=1;
			p->lchild=pre;
		}
		if(p->rchild==NULL) p->rtag=1;
		if(pre!=NULL&&pre->rtag==1) pre->rchild=p;
		pre=p;
		inthreading(p->rchild);	
	}	
}
void postthreading(bithrnode *p)
{
	bithrnode *pre=NULL;
	if(p!=NULL)
	{
		inthreading(p->lchild);
		if(p->lchild==NULL){
			p->ltag=1;
			p->lchild=pre;
		}
		if(p->rchild==NULL) p->rtag=1;
		if(pre!=NULL&&pre->rtag==1) pre->rchild=p;
		pre=p;
		inthreading(p->rchild);	
	}	
}



bithrnode* preordernext(bithrnode *p)
{
	bithrnode *q;
	q=p->rchild;
	if(p->rtag!=1){
		while(q->ltag==0) q=q->lchild;
	}
	return q;
}

bithrnode* postordernext(bithrnode *p)
{
	bithrnode *q;
	q=p->rchild;
	if(p->rtag!=1){
		while(q->ltag==0) q=q->lchild;
	}
	return q;
}
bithrnode* inordernext(bithrnode *p)
{
	bithrnode *q;
	q=p->rchild;
	if(p->rtag!=1){
		while(q->ltag==0) q=q->lchild;
	}
	return q;
}

bithrnode* inorderbefore(bithrnode *p)
{
    bithrnode *pre,*q;
    if (p->ltag==1)    
         pre=p->lchild; 
    else
    {   
        for (q=p->lchild;q->rtag==0;q=q->rchild)
               pre=q;
    }   
        return pre; 
}

bithrnode* preorderbefore(bithrnode *p)
{
	bithrnode *q;
	q=p->rchild;
	if(p->rtag!=1){
		while(q->ltag==0) q=q->lchild;
	}
	return q;
}
bithrnode* postorderbefore(bithrnode *p)
{
	bithrnode *q;
	q=p->rchild;
	if(p->rtag!=1){
		while(q->ltag==0) q=q->lchild;
	}
	return q;
}



void findpreorpost(bithrnode *x,int a,int b)//(a����1ǰ��,����-1���)
// (b����1ǰ������0���� ������-1���� )
{
	bithrnode *o=NULL; 
	if(a==1)//(ֱ��ǰ��)
	{
		if(b==-1)//(ǰ��)
		{
			prethreading(x);
			o=preorderbefore(x);
			printf("%d",o->data);	
			
		}
		else if (b==0)//(����)
		{
			inthreading(x);
			o=inorderbefore(x);
			printf("%d",o->data);	
		}
		else if (b==1)//(����)
		{
			postthreading(x);
			o=postorderbefore(x);
			printf("%d",o->data);		
		}
		else printf("Error");	
	}
	else if(a==-1)//(ֱ�Ӻ��)
	{
		if(b==-1)//(ǰ��)
		{
			prethreading(x);
			o=preordernext(x);
			printf("%d",o->data);		
		}
		else if (b==0)//(����)
		{
			inthreading(x);
			o=inordernext(x);
			printf("%d",o->data);	
		}
		else if (b==1)//(����)
		{
			postthreading(x);
			o=postordernext(x);
			printf("%d",o->data);			
		}
		else printf("Error");	
	}
	else printf("Error");
}

int main(){
	bithrnode *root=NULL;
	findpreorpost(root,-1,0);
	return 0;
}












