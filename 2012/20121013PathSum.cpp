#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

// definition for binary tree
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		//if(!root && !sum)return true;
		//cout<<root->val<<endl;
		if(root){
			if(!root->left && !root->right && root->val==sum)return true;
			if(root->left && hasPathSum(root->left,sum-root->val))return true;
			if(root->right && hasPathSum(root->right,sum-root->val)) return true;
		}
		return false;
	}
};

int main()
{
	Solution sol;
	TreeNode t1(5),t2(4),t3(8),t4(11),t5(13),t6(4),t7(7),t8(2),t9(1);
	t1.left=&t2;t1.right=&t3;
	t2.left=&t4;
	t3.left=&t5;t3.right=&t6;
	t4.left=&t7;t4.right=&t8;
	t6.right=&t9;
	cout<<sol.hasPathSum(&t1,22)<<endl;
	return 0;
}

