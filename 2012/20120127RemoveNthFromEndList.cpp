#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head&&!n)return NULL;
        if(!head->next&&n==1){
            free(head);
            return NULL;
        }
        ListNode *p,*q;
        q=head;p=q->next;

        while(p&&n--)p=p->next;
        if(n>0){
            p=head->next;
            free(head);
            return p;
        }
        while(p){
            p=p->next;
            q=q->next;
        }
        p=q->next;
        q->next=p->next;
        free(p);
        return head;
    }
};
int main()
{
    Solution sol;
    ListNode *p = new ListNode(1);
    ListNode *q = new ListNode(2);
    ListNode *r = new ListNode(3);
    p->next=q;
    q->next=r;
    p=sol.removeNthFromEnd(p,1);
    while(p){
        cout<<p->val<<",";
        p=p->next;
    }
    return 0;
}
