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

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(!head)return NULL;
        if(!head->next)return head;
        ListNode *ans,*p,*ppre,*pnext;
        ans=head->next;
        ppre=head;
        p=head->next;
        pnext=p->next;
        while(ppre&&p){
            ppre->next=pnext;
            p->next=ppre;
            if(pnext&&pnext->next){
                ppre->next=pnext->next;
                ppre=pnext;
                p=pnext->next;
                pnext=p->next;
            }else break;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6);
    l1.next=&l2;
    l2.next=&l3;
    l3.next=&l4;
    l4.next=&l5;
    l5.next=&l6;
    ListNode *ans = sol.swapPairs(&l1);
    ListNode *p=ans;
    while(p){
        cout<<p->val;
        if(p->next)cout<<"->";
        p=p->next;
    }
    cout<<endl;
    return 0;
}
