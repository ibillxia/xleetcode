#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(!num.size())return NULL;
        return sortedArr2BST(num.data(),num.size());
    }
    TreeNode *sortedArr2BST(int* arr,int n){
        if(!n)return NULL;
        if(n==1)return new TreeNode(arr[0]);
        TreeNode *t = new TreeNode(arr[n/2]);
        t->left = sortedArr2BST(arr,n/2);
        if(n>2)t->right = sortedArr2BST(arr+n/2+1,n-n/2-1);
        return t;
    }
};

int main()
{
    Solution sol;
    vector<int> v(4);
    v[0]=0,v[1]=1,v[2]=2,v[3]=3;
    TreeNode* t = sol.sortedArrayToBST(v);
    cout<<t->val<<endl;
    return 0;
}
