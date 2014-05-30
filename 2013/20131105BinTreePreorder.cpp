#include<iostream>
#include<vector>
#include<stack>
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        if(!root)return v;
        stack<TreeNode> st;
        TreeNode t(0);
        st.push(*root);
        while(st.size()){
            t=st.top();
            v.push_back(t.val);
            st.pop();
            if(t.right)st.push(*t.right);
            if(t.left)st.push(*t.left);
        }
        return v;
    }

};

int main()
{
    Solution sol;
    TreeNode t1(1),t2(2),t3(3);
    t1.right=&t2;
    t2.left=&t3;
    vector<int> ans = sol.preorderTraversal(&t1);
    FOR(i,ans.size())cout<<ans[i]<<" ";
    cout<<endl;
	return 0;
}
