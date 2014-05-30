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

// Definition for singly-linked list
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Definition for binary tree
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> vi;
	TreeNode *sortedListToBST(ListNode *head) {
		TreeNode *ans=NULL;
		if(!head) return ans;
		ListNode *p=head;
		while(p){
			vi.push_back(p->val);
			p=p->next;
		}
		ans = createBST(0,vi.size()-1);
		return ans;
	}

	TreeNode *createBST(int l,int r){
		if(l>r)return NULL;
		if(l==r){
			TreeNode *nd = new TreeNode(vi[l]);
			return nd;
		}
		int m = (l+r)/2;
		TreeNode *nd = new TreeNode(vi[m]);
		nd->left = createBST(l,m-1);
		nd->right = createBST(m+1,r);
		return nd;
	}

	void preOrder(TreeNode *root){
		if(root){
			cout<<root->val<<" ";
			if(root->left)cout<<"l:"<<root->left->val<<" ";
			if(root->right)cout<<"r:"<<root->right->val;
			cout<<endl;
			preOrder(root->left);
			preOrder(root->right);
		}
	}
};

int main()
{
	Solution sol;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6);
	l1.next=&l2,l2.next=&l3,l3.next=&l4,l4.next=&l5,l5.next=&l6;
	TreeNode *ans=sol.sortedListToBST(&l1);
	sol.preOrder(ans);
	cout<<endl;
	return 0;
}

