#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

class Solution {
	public:
		vector<int> rightSideView(TreeNode *root) {
			vector<int> res;
			if(root == NULL)
				return res;
			queue<TreeNode*> q;
			q.push(root);
			while(!q.empty())
			{
				res.push_back( q.front()->val );

				int size = q.size();
				for(int i=0;i<size;i++)
				{
					TreeNode *node = q.front();	
					q.pop();
					if(node->right)
						q.push(node->right);
					if(node->left)
						q.push(node->left);
				}
			}

			return res;
		}
				        
};
//test
int main()
{
    TreeNode *root =new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(9);
    //root->right->right->right = new TreeNode(7);

	class Solution s;
	vector<int> res;
	res=s.rightSideView(root);

	vector<int>::iterator iter;
	for(iter=res.begin(); iter != res.end(); ++iter)
	{
		cout<< *iter <<" ";
	}
	cout <<endl;

    return 0;
}
