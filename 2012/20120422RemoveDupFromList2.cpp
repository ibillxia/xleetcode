#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(!head)return NULL;
        if(!head->next)return head;
        int flag;
        ListNode *p=head,*q,*r;
        while(p) {
            q=p->next;
            flag=0;
            while(q&&q->val==p->val) { // delete those equal to p
                p->next=q->next;
                free(q);
                q=p->next;
                flag=1;
            }
            if(flag) { // delete p
                if(p==head) head=q;
                else r->next=q;
                free(p);
            } else if(p) r=p;
            p=q;
        }
        return head;
    }
};
int main()
{
    Solution sol;
    ListNode *p = new ListNode(1);
    ListNode *q = new ListNode(2);
    ListNode *r = new ListNode(2);
    ListNode *t = new ListNode(4);
    p->next=q;
    q->next=r;
    r->next=t;
    p=sol.deleteDuplicates(p);
    while(p) {
        cout<<p->val<<",";
        p=p->next;
    }
    return 0;
}
