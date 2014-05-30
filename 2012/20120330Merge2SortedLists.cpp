#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *head,*p,*q,*pp;
        p=l1,q=l2;
        if(p->val<=q->val)head=p,p=p->next;
        else head=q,q=q->next;
        pp=head;
        while(p&&q){
            if(p->val<=q->val){
                pp->next=p,pp=p,p=p->next;
            }else{
                pp->next=q,pp=q,q=q->next;
            }
        }
		if(!p)pp->next=q;
		if(!q)pp->next=p;
        return head;
    }
};

int main()
{
    Solution sol;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6);
	l1.next=&l3,l3.next=&l6;
	l2.next=&l4,l4.next=&l5;
    ListNode *ans = sol.mergeTwoLists(&l1,&l2);
    return 0;
}
