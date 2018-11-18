
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
}PointerTag;//Link == 0 :指针 ,Thread == 1: 线索 
typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild, *rchild; //左右孩子指针
	struct BiThrNode *parent;
	PointerTag LTag , RTag;            //左右标志 
}BiThrNode, *BiThrTree;
BiThrTree pre;  //全局变量，始终指向刚刚访问过的结点。
 
Status visit(TElemType e){
	printf("%5c",e);
	return OK;
}
//char Vexch[20]={'H','D','A','$','$','C','$','B','$','$','G','F','$','E','$','$','$'};  
char Vexch[26]={'A','B','D','H','$','$','I','$','$','E','J','$','$','$','C','F','$','$','G','$','$'};  
int i=0;  
//二叉树的创建  
Status CreatBiThrTree(BiThrTree &T,BiThrTree &p)  
{  
    if(Vexch[i++]=='$') T=NULL;  
    else  
    {  
        T= (BiThrTree)malloc(sizeof(BiThrNode)); 
        if(!T)  return 0;  
        T->data=Vexch[i-1];//生成根节点  
		T->parent = p;
        visit(T->data);
		T->LTag=Link; 
        CreatBiThrTree(T->lchild,T);//创建左子树 
		T->RTag=Link; 
        CreatBiThrTree(T->rchild,T);//创建右子树  
    }  
    return 1;  
}  
 
void PostThreading(BiThrTree p){
	if(p){
		PostThreading(p->lchild);     //左子树线索化
		PostThreading(p->rchild);     //右子树线索化 
		if(!p->lchild){               //没有左孩子 
			p->LTag = Thread;         //前驱线索 
			p->lchild = pre;          //左孩子指针指向前驱 
		}
		if(pre && !pre->rchild){
			pre->RTag = Thread;       //后继线索
			pre->rchild = p ;         //前驱右孩子指针指向后继 
		}
		pre = p;
	}
}
//后序 遍历线索二叉树 
Status PostOrderTraverse_Thr(BiThrTree T ,Status(* visit)(TElemType e) ){
	BiThrTree p ;
	p = T;            // p指向根节点 
	pre=NULL;
	while(p != NULL){            //空树 或者遍历结束时 p == T
		while(p->LTag == Link )         // 走到最左结点  ||左结点
			p = p->lchild;
		 
		while(p->RTag == Thread ){      //访问后继       ||右结点
			visit(p->data);
			pre = p;
			p = p->rchild ;            
		}
		if(p == T){                     //是否是最后根节点
			visit(p->data); 
			break;
		}
		while(p && p->rchild == pre  ){ //访问根         ||根节点
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
	printf("创建树\n");
	pre = NULL;
	CreatBiThrTree(PostT,pre);
	printf("\n后序遍历线索二叉树\n");
	PostThreading(PostT);
	PostOrderTraverse_Thr(PostT , visit);
	printf("\n");	
	return 0;
}


