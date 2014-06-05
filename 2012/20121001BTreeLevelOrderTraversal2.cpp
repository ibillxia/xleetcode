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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<int> vi;
		vector<TreeNode*> v1,v2;
		vector<vector<int> > ans;
		if(!root)return ans;
		v1.push_back(root);
		vi.push_back(root->val);
		int i;
		TreeNode *tn;
		while(v1.size()){
			ans.insert(ans.begin(),vi);
			vi.clear();
			for(i=0;i<v1.size();i++){
				tn=v1[i];
				if(tn->left){
					v2.push_back(tn->left);
					vi.push_back(tn->left->val);
				}
				if(tn->right){
					v2.push_back(tn->right);
					vi.push_back(tn->right->val);
				}
			}
			v1.clear();
			swap(v1,v2);
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7),t8(8),t9(9);
	t1.left=&t2;t1.right=&t3;
	t2.right=&t4;
	t4.left=&t5;t4.right=&t6;
	vector<vector<int> > ans = sol.levelOrder(&t1);
	FOR(i,ans.size()){
		FOR(j,ans[i].size())cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

