/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root) {
            int d1=0,d2=0;
            if(root->left)d1=minDepth(root->left);
            if(root->right)d2=minDepth(root->right);
            if(!d1 && !d2)return 1;
            else if(!d1)return d2+1;
            else if(!d2)return d1+1;
            return d1<d2?d1+1:d2+1;
        }
        return 0;
    }
};