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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode *root) {
		if(!root)return 0;
		ans=num=0;
		dfs(root);
		return ans;
	}
private:
	int num,ans;
	int dfs(TreeNode *root){
		num=num*10+root->val;
		if(!root->left && !root->right)ans+=num;
		if(root->left)dfs(root->left);
		if(root->right)dfs(root->right);
		num=num/10;
	}
};

int main()
{
	Solution sol;
	TreeNode tn1(1),tn2(2),tn3(3),tn4(4),tn5(5);
	tn1.left=&tn2;
	tn1.right=&tn3;
	tn2.left=&tn4;
	tn2.right=&tn5;
	cout<<sol.sumNumbers(&tn1)<<endl;
	return 0;
}

