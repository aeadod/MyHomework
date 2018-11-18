#include <stdio.h> 
#include <stdlib.h>  
typedef struct node
{
	int data;
	struct node *lchild, *rchild;
}Bitree;
Bitree *B[100];
Bitree *CreateBiTree()
{
	int num, i, n;
	Bitree *t, *s;
	t = NULL;
	printf("������������-1��ʾΪ���㣬-2��ʾ�����������\n");
	num = 0;
	scanf("%d", &n);
	while (n != -2)
	{
		s = (Bitree *)malloc(sizeof(Bitree));
		s->data = n;
		s->lchild = s->rchild = NULL;
		num++;
		if (!t)
			t = s;
		B[num] = s;
		scanf("%d", &n);
	}
	for (i = 1; i <= num; i++)
	{
		if (B[i]->data != 1)
		{
			if (2 * i <= num && B[2 * i]->data != -1)
				B[i]->lchild = B[2 * i];
			if (2 * i + 1 <= num && B[2 * i + 1]->data != -1)
				B[i]->rchild = B[2 * i + 1];
		}
	}
	return t;
}
int IsSearchTree(const Bitree *t)  //�ݹ�����������Ƿ�Ϊ����������  
{
	if (!t)        //�ն��������  
		return 1;
	else if (!(t->lchild) && !(t->rchild))   //���������������  
		return 1;
	else if ((t->lchild) && !(t->rchild))    //ֻ�����������  
	{
		if (t->lchild->data > t->data)	//��������ֵ���丸�ڵ�󣬷���0���Ƕ���������
			return 0;
		else
			return IsSearchTree(t->lchild);	//�ݹ�������
	}
	else if ((t->rchild) && !(t->lchild))   //ֻ�����������  
	{
		if (t->rchild->data < t->data)		//��������ֵ���丸�ڵ�ֵС������0���Ƕ���������
			return 0;
		else
			return IsSearchTree(t->rchild);	//�ݹ�������
	}
	else         //��������ȫ�����  
	{
		if ((t->lchild->data > t->data) || (t->rchild->data < t->data))		//��������ֵ���丸�ڵ�������������ֵ���丸�ڵ�ֵС������0���Ƕ���������
			return 0;
		else
			return (IsSearchTree(t->lchild) && IsSearchTree(t->rchild));	//�ݹ�������
	}
}
int main(void)
{
	int flag = 0;
	Bitree *tree;
	tree = CreateBiTree();
	flag = IsSearchTree(tree);
	if (flag)
		printf("������Ƕ�����������\n");
	else
		printf("��������Ƕ�����������\n");
	system("pause");
	return 0;
}
