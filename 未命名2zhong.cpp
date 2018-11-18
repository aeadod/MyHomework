#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
       int val;
      TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
TreeNode* getRightNode(TreeNode* root)
{
  if(root ==NULL)  return NULL;
  while(root->right !=NULL)
      root = root->right;
  return root;
}


TreeNode* getPNode(TreeNode* root,int value,TreeNode*& parent,TreeNode*& firstRParent)
{
    while(root)
    {
        if(root->val == value)
            return root;

        parent = root;
        if(root->val>value)
        {
            root = root->left;
        }else{
            firstRParent = root;//�����ҹյ�
            root = root->right;
        }
    }

    return NULL;
}
//������
TreeNode*  getPreNode(TreeNode* root, int value)
{
     if(root)
     {
           TreeNode* parent =NULL;
           TreeNode* firstRParent =NULL;

          TreeNode* node = getPNode(root,value,parent ,firstRParent );
          if(node == NULL)
                  return node;
          if(node->left) //��������
             return getRightNode(node->right);

          if(NULL == parent ||(parent && (NULL == firstRParent))) return NULL; //û��ǰ���ڵ�����

          if(node == parent->right) //û�������� ���丸�ڵ���ұ߽ڵ� 
              return parent;
          else//û�������� ���丸�ڵ����߽ڵ� 
           {
               return firstRParent ;
           }

     }
    return root;
}
TreeNode *CREATREE()
{
	char ch;
	TreeNode *q[1024];
	int front ,rear;
	TreeNode *root,*s;
	root =NULL;
	front =1;rear =0;
	while((ch=getchar())!='#'){
		s=NULL;
		if (ch!='@'){
			s=(TreeNode*)malloc(sizeof(TreeNode));
			s->val=ch;
			s->left =NULL;
			s->right =NULL;
			
		}
		rear ++;
		q[rear]=s;
		if(rear==1){
			root =s;
			
		}
		else {
			if(s&&q[front])
				if(rear%2==0) q[front]->left=s;
				else q[front]->right=s;
				if(rear%2==1) front++;
		}
	}
	return root;
}
int main()
{
	TreeNode *p=CREATREE();
	TreeNode *x=getPreNode(p, 5);
	printf("%d ",x->val);
}
