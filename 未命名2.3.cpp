
#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdlib.h>
using namespace std;
#define Status int 
#define OK 1
#define ERROR 0
#define TElemType char
typedef enum{
	Link,Thread
}PointerTag;//Link == 0 :ָ�� ,Thread == 1: ���� 
typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild, *rchild; //���Һ���ָ��
	struct BiThrNode *parent;
	PointerTag LTag , RTag;            //���ұ�־ 
}BiThrNode, *BiThrTree;
BiThrTree pre;  //ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ�㡣
 
Status visit(TElemType e){
	printf("%5c",e);
	return OK;
}
//char Vexch[20]={'H','D','A','$','$','C','$','B','$','$','G','F','$','E','$','$','$'};  
char Vexch[26]={'A','B','D','H','$','$','I','$','$','E','J','$','$','$','C','F','$','$','G','$','$'};  
int i=0;  
//�������Ĵ���  
Status CreatBiThrTree(BiThrTree &T,BiThrTree &p)  
{  
    if(Vexch[i++]=='$') T=NULL;  
    else  
    {  
        T= (BiThrTree)malloc(sizeof(BiThrNode)); 
        if(!T)  return 0;  
        T->data=Vexch[i-1];//���ɸ��ڵ�  
		T->parent = p;
        visit(T->data);
		T->LTag=Link; 
        CreatBiThrTree(T->lchild,T);//���������� 
		T->RTag=Link; 
        CreatBiThrTree(T->rchild,T);//����������  
    }  
    return 1;  
}  
 
void PostThreading(BiThrTree p){
	if(p){
		PostThreading(p->lchild);     //������������
		PostThreading(p->rchild);     //������������ 
		if(!p->lchild){               //û������ 
			p->LTag = Thread;         //ǰ������ 
			p->lchild = pre;          //����ָ��ָ��ǰ�� 
		}
		if(pre && !pre->rchild){
			pre->RTag = Thread;       //�������
			pre->rchild = p ;         //ǰ���Һ���ָ��ָ���� 
		}
		pre = p;
	}
}
//���� �������������� 
Status PostOrderTraverse_Thr(BiThrTree T ,Status(* visit)(TElemType e) ){
	BiThrTree p ;
	p = T;            // pָ����ڵ� 
	pre=NULL;
	while(p != NULL){            //���� ���߱�������ʱ p == T
		while(p->LTag == Link )         // �ߵ�������  ||����
			p = p->lchild;
		 
		while(p->RTag == Thread ){      //���ʺ��       ||�ҽ��
			visit(p->data);
			pre = p;
			p = p->rchild ;            
		}
		if(p == T){                     //�Ƿ��������ڵ�
			visit(p->data); 
			break;
		}
		while(p && p->rchild == pre  ){ //���ʸ�         ||���ڵ�
			visit(p->data);
			pre = p;
			p = p->parent;
		}
		if(p && p->RTag == Link)
			p = p->rchild;
	}
	return OK;
}
int main()
{
	BiThrTree PostT;
	printf("������\n");
	pre = NULL;
	CreatBiThrTree(PostT,pre);
	printf("\n�����������������\n");
	PostThreading(PostT);
	PostOrderTraverse_Thr(PostT , visit);
	printf("\n");	
	return 0;
}


