#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024

typedef char datatype;
typedef struct node {
	datatype data;
	struct node * lchild;
	struct node * rchild;
}bitree;

bitree *CREATREE()
{
	char ch;
	bitree *q[maxsize];
	int front ,rear;
	bitree *root,*s;
	root =NULL;
	front =1;rear =0;
	while((ch=getchar())!='#'){
		s=NULL;
		if (ch!='@'){
			s=(bitree*)malloc(sizeof(bitree));
			s->data=ch;
			s->lchild =NULL;
			s->rchild =NULL;
			
		}
		rear ++;
		q[rear]=s;
		if(rear==1){
			root =s;
			
		}
		else {
			if(s&&q[front])
				if(rear%2==0) q[front]->lchild=s;
				else q[front]->rchild=s;
				if(rear%2==1) front++;
		}
	}
	return root;
}

int putRootofx(bitree *T, int x)
{
    if(!T)
        return 0;
    if(T->data == x){
        return 1;
    }
    if(T){
        if(putRootofx(T->lchild, x) || putRootofx(T->rchild, x)){
            printf("%c ",T->data);
            return 1;
        }
    }
    return 0;
}

void inorder(bitree*p)
{
	if (p!=NULL){
		inorder(p->lchild);
		printf("%d",p->data);
		inorder(p->rchild);
	}
}

int main()
{
	bitree *o=CREATREE();
	inorder(o);
	putRootofx(o, 5);
 } 
