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

// Definition for binary tree
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		if(n==0) return generateTrees(1,0);
		return generateTrees(1,n);
	}
private:
	vector<TreeNode *> generateTrees(int start, int end){
		vector<TreeNode *> ans;
		if(start > end){
			ans.push_back(NULL);
			return ans;
		}
		int k;
		vector<TreeNode*>::iterator i,j;
		for(k=start;k<=end;k++){
			vector<TreeNode *> leftTree = generateTrees(start,k-1);
			vector<TreeNode *> rightTree = generateTrees(k+1,end);
			for(i=leftTree.begin();i!=leftTree.end();i++){
				for(j=rightTree.begin();j!=rightTree.end();j++){
					TreeNode *tn = new TreeNode(k);
					tn->left = *i;
					tn->right = *j;
					ans.push_back(tn);
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	int n;
	vector<TreeNode *> ans;
	while(cin>>n){
		ans = sol.generateTrees(n);
		cout<<ans.size()<<endl;
	}
	return 0;
}

