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
	PointerTag LTag , RTag;            //左右标志 
}BiThrNode, *BiThrTree;
 
//char Vexch[20]={'H','D','A','$','$','C','$','B','$','$','G','F','$','E','$','$','$'};  
char Vexch[26]={'A','B','D','H','$','$','I','$','$','E','J','$','$','$','C','F','$','$','G','$','$'};  
int i=0;  
//二叉树的创建  
Status CreatBiThrTree(BiThrTree &T)  
{  
    if(Vexch[i++]=='$') T=NULL;  
    else  
    {  
        T= (BiThrTree)malloc(sizeof(BiThrNode)); 
        if(!T)  return 0;  
        T->data=Vexch[i-1];//生成根节点  
        printf("%5c",T->data);
        T->LTag=Link;  
        CreatBiThrTree(T->lchild);//创建左子树 
		T->RTag=Link; 
        CreatBiThrTree(T->rchild);//创建右子树  
    }  
    return 1;  
}  
Status visit(TElemType e){
	printf("%5c",e);
	return OK;
}
 
BiThrTree pre;  //全局变量，始终指向刚刚访问过的结点。 
void InThreading(BiThrTree p){
	if(p){
		InThreading(p->lchild);     //左子树线索化
		if(!p->lchild){             //没有左孩子 
			p->LTag = Thread;       //前驱线索 
			p->lchild = pre;        //左孩子指针指向前驱 
		}
		if(!pre->rchild){
			pre->RTag = Thread;       //后继线索
			pre->rchild = p ;         //前驱右孩子指针指向后继 
		}
		pre = p;
		InThreading(p->rchild);   //右子树线索化 
	}
}
//建立头结点，中序线索二叉树 
Status InOrderThreading(BiThrTree &Thrt,BiThrTree T){
	//中序遍历二叉树T，并将其中序线索化，Thrt指向头结点。
	if(!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) 
		return ERROR;
	 
	Thrt->RTag = Link;  //建头结点
	Thrt->rchild = Thrt ;                    //右指针回指 
	if(!T){
		Thrt->lchild = Thrt;
		Thrt->LTag = Link;
	}else{
		pre = Thrt ;
		Thrt->lchild = T; 
		Thrt->LTag = Link;
		InThreading(T); 
		pre->rchild = Thrt ; 
		pre->RTag = Thread; 
		Thrt->rchild = pre;
	}
	return OK;
}
//中序 遍历线索二叉树 
Status InOrderTraverse_Thr(BiThrTree T ,Status(* visit)(TElemType e) ){
	//T指向头结点，头结点的左链lchild指向根节点，可参见线索化算法
	//中序遍历二叉线索树T的非递归算法，对每个数据元素调用函数visit
	BiThrTree p ;
	p = T->lchild;            // p指向根节点 
	while(p != T){                      //空树 或者遍历结束时 p == T
		while(p->LTag == Link )         // 走到最左结点 
			p = p->lchild;
		visit(p->data);  
		while(p->RTag == Thread && p->rchild !=T){
			p = p->rchild ;             // 若有右线索， 
			visit(p->data);
		}
		p = p->rchild;
	}
	return OK;
}
int main()
{
	BiThrTree T, inorderT;
	printf("创建树\n");
	CreatBiThrTree(T);
	printf("\n中序遍历线索二叉树\n");
	InOrderThreading(inorderT , T);
	InOrderTraverse_Thr(inorderT , visit);
	printf("\n");
	return 0;
}

