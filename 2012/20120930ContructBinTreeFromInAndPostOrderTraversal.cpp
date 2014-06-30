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
	TreeNode *buildTree(vector<int> &in, vector<int> &post) {
		if(in.empty())return NULL;
		return buildTree(in.begin(),post.begin(),in.size());
    }
private:
	TreeNode *buildTree(vector<int>::iterator in, vector<int>::iterator post, int n) {
		if(!n)return NULL;
		int i;
		for(i=0;i<n;i++){
			if(post[n-1] == in[i])break;
		}
		TreeNode *tn = new TreeNode(post[n-1]);
		tn->left = buildTree(in,post,i);
		tn->right = buildTree(in+1+i,post+i,n-i-1);
		return tn;
    }
};

int main()
{
    Solution sol;

	int n;
	while(cin>>n){
		vector<int> in(n);
		vector<int> post(n);
		FOR(i,n)cin>>in[i];
		FOR(i,n)cin>>post[i];
		TreeNode *root = sol.buildTree(in,post);
	}
    return 0;
}
