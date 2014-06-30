#include<iostream>
#include<vector>
#include<stack>
#include<string>
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
	bool isValidBST(TreeNode *root) {
        if(!root)return true;
        if(!root->left && !root->right)return true;
		int pre = 0;
		bool bStart=false;
		return isValidBST(root,pre,bStart);
    }
private:
	bool isValidBST(TreeNode *root,int &pre,bool &bs){
		if(root){
			if(root->left){
				if(!isValidBST(root->left,pre,bs))return false;
			}
			//cout<<root->val<<" "<<pre<<endl;
			if(bs==true){
				if(root->val > pre){
					pre = root->val;
					//return true;
				}else return false;
			}else {
				pre = root->val;
				bs=true;
			}
			if(root->right){
				if(!isValidBST(root->right,pre,bs))return false;
			}
		}
		return true;
	}
};

int main()
{
    Solution sol;
    TreeNode tn1(1),tn2(2),tn3(3),tn4(4),tn5(5);
	tn3.left=&tn1;tn3.right=&tn4;
	tn4.left=&tn2;tn4.right=&tn5;
	cout<<sol.isValidBST(&tn3)<<endl;
    return 0;
}
