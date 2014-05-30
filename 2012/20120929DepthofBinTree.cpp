#include<iostream>
#include<deque>
#include<cstdio>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {}
    TreeNode(int v): val(v),left(NULL),right(NULL){}
};

class Solution{
public:
    int maxDepth(TreeNode* root)
    {
        if(root) {
            int d1=0,d2=0;
            d1=maxDepth(root->left);
            d2=maxDepth(root->right);
            return d1>d2?d1+1:d2+1;
        } else return 0;
    }

    // find by BFS
    int maxDepth2(TreeNode* root)
    {
        if(!root)return 0;
        int depth=0;
        TreeNode tn(root->val);
        deque<TreeNode> dq;
        deque<TreeNode>::reverse_iterator it,it2;
        dq.push_back(*root);
        while(dq.size()) {
            it2=dq.rend();
            for(it=dq.rbegin(); it!=it2; it++) {
                tn=dq.front();
                if(tn.left)dq.push_back(*(tn.left));
                if(tn.right)dq.push_back(*(tn.right));
                dq.pop_front();
            }
            depth++;
        }
        return depth;
    }

    TreeNode* createBinTree()
    {
        int v;
        if(~scanf("%d%*c",&v) && v) {
            TreeNode* root=new TreeNode(v);
            root->left=createBinTree();
            root->right=createBinTree();
            return root;
        } else return NULL;
    }

    void printBinTree(TreeNode* root)
    {
        if(root) {
            cout<<root->val<<",";
            printBinTree(root->left);
            printBinTree(root->right);
        } else {
            cout<<"0,";
        }
    }
};

int main()
{
    Solution sol;
    TreeNode t0(0),t1(1),t2(2),t3(3),t4(4),t5(5);
    t0.left=&t1;
    t1.left=&t2;
    t1.right=&t3;
    t2.right=&t4;
    t4.left=&t5;
    cout<<sol.maxDepth(&t0)<<endl;
    cout<<sol.maxDepth2(&t0)<<endl;

    TreeNode *t = new TreeNode;
    freopen("20120929DepthofBinTree.in","r",stdin);
    t=sol.createBinTree();
    //sol.printBinTree(t);
    cout<<sol.maxDepth(t)<<endl;
    cout<<sol.maxDepth2(t)<<endl;
    delete t;
    return 0;
}
