#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
		if(pre.empty() && in.empty())return NULL;
		return buildTree(pre.begin(),in.begin(),pre.size());
    }
private:
	TreeNode *buildTree(vector<int>::iterator pre, vector<int>::iterator in, int n) {
		if(!n)return NULL;
		int i;
		for(i=0;i<n;i++){
			if(*pre == in[i])break;
		}
		TreeNode *tn = new TreeNode(pre[0]);
		tn->left = buildTree(pre+1,in,i);
		tn->right = buildTree(pre+1+i,in+i+1,n-i-1);
		return tn;
    }
};

int main()
{
    Solution sol;

	int n;
	while(cin>>n){
		vector<int> pre(n);
		vector<int> in(n);
		FOR(i,n)cin>>pre[i];
		FOR(i,n)cin>>in[i];
		TreeNode *root = sol.buildTree(pre,in);
	}
    return 0;
}
