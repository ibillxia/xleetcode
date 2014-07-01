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

// definition of binary tree
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recoverTree(TreeNode *root) {
		TreeNode *tn,*pre=NULL,*tn1=NULL,*tn2=NULL;
		stack<TreeNode*> st;
		st.push(root);
		map<TreeNode*,bool> mp;
		while(st.size()){ // Inorder traverse
			tn=st.top();
			if(tn->left && !mp.count(tn->left)){
				st.push(tn->left);
				continue;
			}
			if(!pre)pre=tn;
			else if(tn->val < pre->val){
				if(!tn1)tn1=pre;
				tn2=tn;
			}
			st.pop();
			pre = tn;
			mp[pre]=true;
			if(tn->right){
				st.push(tn->right);
			}
		}
		swap(tn1->val,tn2->val);
		return;
	}
};

int main()
{
	Solution sol;
	TreeNode tn1(1),tn2(4),tn3(3),tn4(2),tn5(5);
	tn3.right=&tn4;tn4.right=&tn5;
	tn3.left=&tn1;tn1.right=&tn2;
	sol.recoverTree(&tn3);
	return 0;
}

