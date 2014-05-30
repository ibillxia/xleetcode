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


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> ans;
	vector<int> postorderTraversal(TreeNode *root) {
        if(!root) return ans;
		if(root->left) postorderTraversal(root->left);
		if(root->right) postorderTraversal(root->right);
		ans.push_back(root->val);
		return ans;
    }
};

int main()
{
    Solution sol;
	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5);
	t1.right = &t2;
	t2.left = &t3;
	vector<int> ans = sol.postorderTraversal(&t1);
	FOR(i,ans.size())cout<<ans[i]<<" ";
	cout<<endl;
    return 0;
}
