#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
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
    bool m_isBala;
    bool isBalanced(TreeNode *root) {
        if(!root)return true;
        m_isBala=true;
        getDepth(root);
        return m_isBala;
    }
    int getDepth(TreeNode *root){
        if(!root)return 0;
        if(m_isBala){
            int d1,d2;
            d1=getDepth(root->left)+1;
            d2=getDepth(root->right)+1;
            if(abs(d1-d2)>1)m_isBala=false;
            else return max(d1,d2);
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    TreeNode t0(0),t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7),t8(8),t9(9);
    t0.left=&t1,t0.right=&t2;
    //t1.left=&t3,t2.right=&t4;
    //t3.right=&t5,t4.left=&t6;
    bool ans = sol.isBalanced(&t0);
    cout<<ans<<endl;
    return 0;
}
