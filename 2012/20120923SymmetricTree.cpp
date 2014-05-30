#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
    bool isSymmetric(TreeNode *root) {
        if(!root)return true;
        if(!root->left&&!root->right)return true;
        if(!root->left||!root->right)return false;
        queue<TreeNode*> qleft,qright;
        TreeNode *tleft,*tright;
        qleft.push(root->left);
        qright.push(root->right);
        while(qleft.size()&&qright.size()){
            tleft=qleft.front(),tright=qright.front();
            qleft.pop(),qright.pop();
            if(tleft->val!=tright->val)return false;
            if(tleft->left&&tright->right)qleft.push(tleft->left),qright.push(tright->right);
            else if(!tleft->left&&tright->right || (tleft->left&&!tright->right))return false;
            if(tleft->right&&tright->left)qleft.push(tleft->right),qright.push(tright->left);
            else if(!tleft->right&&tright->left || (tleft->right&&!tright->left))return false;
        }
        if(qleft.size()||qright.size())return false;
        return true;
    }
};

int main()
{
    Solution sol;
    TreeNode t0(0),t1(1),t2(1),t3(3),t4(3),t5(5),t6(6),t7(7),t8(8),t9(9);
    t0.left=&t1;
    t0.right=&t2;
    t1.left=&t3;
    t2.left=&t4;
    //t3.right=&t5,t4.left=&t6;
    bool ans = sol.isSymmetric(&t0);
    cout<<ans<<endl;
    return 0;
}
