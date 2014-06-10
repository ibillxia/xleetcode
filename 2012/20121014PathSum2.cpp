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
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > ans;
		vector<int> match;
		solve(ans,match,root,sum);
		return ans;
	}
	void solve(vector<vector<int> > &ans,vector<int> match,TreeNode *root, int sum){
		if(root){
			match.push_back(root->val);
			sum-=root->val;
			if(!root->left && !root->right && !sum){
				ans.push_back(match);
				sum+=match.back();
				match.pop_back();
			}
			if(root->left)solve(ans,match,root->left,sum);
			if(root->right)solve(ans,match,root->right,sum);
		}
	}
};

int main()
{
	Solution sol;
	TreeNode t1(5),t2(4),t3(8),t4(11),t5(13),t6(4),t7(7),t8(2),t9(5),t10(1);
	t1.left=&t2;t1.right=&t3;
	t2.left=&t4;
	t3.left=&t5;t3.right=&t6;
	t4.left=&t7;t4.right=&t8;
	t6.left=&t9;t6.right=&t10;
	vector<vector<int> > ans = sol.pathSum(&t1,22);
	FOR(i,ans.size()){
		FOR(j,ans[i].size())cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

