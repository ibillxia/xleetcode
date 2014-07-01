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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ans;
		if(!root)return ans;
		vector<TreeNode*> vc1,vc2;
		vector<int> vi1,vi2;
		vc1.push_back(root);
		vi1.push_back(root->val);
		int i,flag=0;
		while(vc1.size()){
			for(i=0;i<vc1.size();i++){
				if(vc1[i]->left){
					vc2.push_back(vc1[i]->left);
					vi2.push_back(vc1[i]->left->val);
				}
				if(vc1[i]->right){
					vc2.push_back(vc1[i]->right);
					vi2.push_back(vc1[i]->right->val);
				}
			}
			if(!flag){
				ans.push_back(vi1);
				flag=1;
			}else{
				reverse(vi1.begin(),vi1.end());
				ans.push_back(vi1);
				flag=0;
			}
			vc1 = vc2;
			vi1 = vi2;
			vc2.clear();
			vi2.clear();
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	TreeNode tn1(1),tn2(2),tn3(3),tn4(4),tn5(5);
	tn1.left=&tn2;tn1.right=&tn3;
	tn3.left=&tn4;tn3.right=&tn5;
	vector<vector<int> > ans = sol.zigzagLevelOrder(&tn1);
	FOR(i,ans.size()){
		FOR(j,ans[i].size()) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

