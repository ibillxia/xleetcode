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
#include<climits>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

// definition for binary tree
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode *root) {
		if(!root)return 0;
		if(!root->left&&!root->right)return root->val;
		ans=INT_MIN;
		dfs(root);
		return ans;
	}
private:
	int ans;
	int dfs(TreeNode *root){
		if(!root)return 0;
		int ml=dfs(root->left);
		int mr=dfs(root->right);
		int mx=root->val;
		if(ml>0)mx+=ml;
		if(mr>0)mx+=mr;
		if(ans<mx)ans=mx;
		int t=max(ml,mr);
		return t>0 ? root->val + t : root->val;
	}
};

int main()
{
	Solution sol;
	TreeNode tn1(-1),tn2(2),tn3(3);
	tn1.left = &tn2;
	tn1.right = &tn3;
	cout<<sol.maxPathSum(&tn1)<<endl;
	return 0;
}

