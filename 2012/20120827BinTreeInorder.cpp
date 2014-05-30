#include<iostream>
#include<vector>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        if(!root)return v;
        stack<TreeNode*> st;
        map<TreeNode*, bool> mb;
        TreeNode *t=root;
        st.push(t);
        while(t->left)st.push(t->left),t=t->left;
        while(st.size()){
            t=st.top();
            while(t->left&&!mb.count(t->left))st.push(t->left),t=t->left;
            v.push_back(t->val);
            mb.insert(make_pair(t,true));
            st.pop();
            if(t->right)st.push(t->right);
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
    vector<int> ans = sol.inorderTraversal(&t1);
    FOR(i,ans.size())cout<<ans[i]<<" ";
    cout<<endl;
	return 0;
}
