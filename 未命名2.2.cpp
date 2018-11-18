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
	PointerTag LTag , RTag;            //���ұ�־ 
}BiThrNode, *BiThrTree;
 
//char Vexch[20]={'H','D','A','$','$','C','$','B','$','$','G','F','$','E','$','$','$'};  
char Vexch[26]={'A','B','D','H','$','$','I','$','$','E','J','$','$','$','C','F','$','$','G','$','$'};  
int i=0;  
//�������Ĵ���  
Status CreatBiThrTree(BiThrTree &T)  
{  
    if(Vexch[i++]=='$') T=NULL;  
    else  
    {  
        T= (BiThrTree)malloc(sizeof(BiThrNode)); 
        if(!T)  return 0;  
        T->data=Vexch[i-1];//���ɸ��ڵ�  
        printf("%5c",T->data);
		T->LTag=Link; 
        CreatBiThrTree(T->lchild);//���������� 
		T->RTag=Link; 
        CreatBiThrTree(T->rchild);//����������  
    }  
    return 1;  
}  
Status visit(TElemType e){
	printf("%c ",e);
	return OK;
}
 
BiThrTree pre;  //ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ�㡣 
void PreThreading(BiThrTree p){
	if(p){
		if(!p->lchild){             //û������ 
			p->LTag = Thread;       //ǰ������ 
			p->lchild = pre;        //����ָ��ָ��ǰ�� 
		}
		if(!pre->rchild){
			pre->RTag = Thread;       //�������
			pre->rchild = p ;         //ǰ���Һ���ָ��ָ���� 
		}
		pre = p;
		if(p->LTag == Link)
			PreThreading(p->lchild);     //������������
		if(p->RTag == Link)
			PreThreading(p->rchild);   //������������ 
	}
}
//����ͷ��㣬ǰ������������ 
Status PreOrderThreading(BiThrTree &Thrt,BiThrTree T){
	//ǰ�����������T��������ǰ����������Thrtָ��ͷ��㡣
	if(!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) 
		return ERROR;
	
	Thrt->RTag = Thread;               //��ͷ���
	Thrt->rchild = Thrt ;              //��ָ���ָ 
	Thrt->LTag = Link;
	if(!T){
		Thrt->lchild = Thrt;
	}else{
		Thrt->lchild = T; 
		pre = Thrt ;
		PreThreading(T); 
		pre->rchild = Thrt ; 
		pre->RTag = Thread; 
		Thrt->rchild = pre;
	}
	return OK;
}
//ǰ�� �������������� 
Status PreOrderTraverse_Thr(BiThrTree T ,Status(* visit)(TElemType e) ){
	//Tָ��ͷ��㣬ͷ��������lchildָ����ڵ㣬�ɲμ��������㷨
	//ǰ���������������T�ķǵݹ��㷨����ÿ������Ԫ�ص��ú���visit
	BiThrTree p ;
	p = T->lchild;            // pָ����ڵ� 
	while(p != T){            //���� ���߱�������ʱ p == T
		visit(p->data);  
		if(p->LTag == Link)
			p = p->lchild;
		else 
			p = p->rchild;
	}
	return OK;
}
int main()
{
	BiThrTree T, PreT;
	printf("������\n");
	CreatBiThrTree(T);
	printf("\nǰ���������������\n");
	PreOrderThreading(PreT , T);
	PreOrderTraverse_Thr(PreT , visit);
	
	printf("\n");
	return 0;
}

