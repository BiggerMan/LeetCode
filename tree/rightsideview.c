#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* newNode(int val)
{
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = val;

	return node;
}
//paste from this on LeetCode

void rightView(struct TreeNode *root, int *maxLevel, int curLevel,int res[],int *count)
{
	if(NULL == root) return;

	if(*maxLevel < curLevel)//BFS in every level,from right side.
	{
		res[*count]=root->val;
		++(*count);
		*maxLevel = curLevel;
	}
	rightView(root->right,maxLevel,curLevel+1,res,count);//begin from right
	rightView(root->left,maxLevel,curLevel+1,res,count);
}

int *rightSideView(struct TreeNode *root, int *n)
{
	if(root == NULL)
	{
		*n=0;
		return (int*)0;
	}
	int *res = (int*)malloc(*n);
	int maxlevel=0;//tree level
	int count=0;
	rightView(root,&maxlevel,1,res,&count);
	*n = count;

	return res;
}

//test
int main()
{
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->right->right = newNode(9);
    root->left->left->left->left = newNode(10);

	int *res;
	int n=8;
	//res=rightSideView(NULL, &n);
	res=rightSideView(root, &n);
    //rightView(root);
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d ",res[i]);	
	}
	printf("\n");

    return 0;
}
