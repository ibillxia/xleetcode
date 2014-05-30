#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

// Definition for binary tree
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode *root) {
		if(!root)return;
		stack<TreeNode*> st;
		TreeNode *tn,*pre=NULL;
		st.push(root);
		while(st.size()){
			tn=st.top();
			st.pop();
			//cout<<tn->val<<" ";
			if(pre)pre->left=NULL,pre->right=tn;
			if(tn->right)st.push(tn->right);
			if(tn->left)st.push(tn->left);
			pre=tn;
		}
		//cout<<endl;
		return;
	}
};

int main()
{
	Solution sol;
	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6);
	t1.left=&t2;
	t1.right=&t5;
	t2.left=&t3;
	t2.right=&t4;
	t5.right=&t6;
	sol.flatten(&t1);
	return 0;
}

