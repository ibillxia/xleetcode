#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        queue<TreeLinkNode*> *pq1,*pq2,qt1,qt2;
        TreeLinkNode *t,*tpre;
        qt1.push(root);
        pq1=&qt1,pq2=&qt2;
        while((*pq1).size()){
            tpre=NULL;
            while((*pq1).size()){
                t=qt1.front();
                if(t->left)(*pq2).push(t->left);
                if(t->right)(*pq2).push(t->right);
                if(!tpre)tpre=t;
                else tpre->next=t,tpre=t;
                (*pq1).pop();
            }
            swap(*pq1,*pq2);
        }
        return;
    }
};


int main()
{
    Solution sol;
    TreeLinkNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7);
    t1.left=&t2;t1.right=&t3;
	t2.left=&t4;//t2.right=&t5;
	t3.left=&t6;//t3.right=&t7;
    sol.connect(&t1);
	return 0;
}
