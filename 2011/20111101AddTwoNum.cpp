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
/*
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) { // TLE, why?
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *p,*pp,*q;
        p=l1,q=l2;
        int t=0;
        while(p&&q){
            t=t+p->val+q->val;
            p->val=t%10;
            t/=10;
            pp=p,p=p->next,q=q->next;
        }
        if(q)pp->next=p=q;
        while(p){
            t=t+p->val;
            p->val=t%10;
			t/=10;
			pp=p,p=p->next;
        }
		if(t)pp->next = new ListNode(t);
        return l1;
    }
    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) { //TLE, why?
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *p,*pp,*q,*ans;
        p=l1,q=l2,pp=ans=NULL;
        int t=0;
        while(p||q){
            if(p)t+=p->val,p=p->next;
            if(q)t+=q->val,q=q->next;
            ListNode *ln= new ListNode(t%10);
            if(!pp)pp=ans=ln;
            else pp->next=ln,pp=ln;
            t/=10;
        }
		if(t)pp->next = new ListNode(t);
        return ans;
    }
*/
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)  // AC, 208ms
    {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *p,*pp,*q;
        p=l1,q=l2;
        int t=0;
        while(p&&q) {
            t=t+p->val+q->val;
            p->val=t%10;
            t/=10;
            pp=p;
            p=p->next;
			q=q->next;
        }
        if(q)pp->next=p=q;
        while(p&&t) { // if t==0, no need to do
            t=t+p->val;
            p->val=t%10;
            t/=10;
            pp=p;
			p=p->next;
        }
        if(t)pp->next = new ListNode(t);
        return l1;
    }
    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) // AC, 272ms
    {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *p,*pp,*q,*ans;
        p=l1,q=l2,pp=ans=NULL;
        int t=0;
        while(p||q) {
			if(p){t+=p->val;p=p->next;}
			if(q){t+=q->val;q=q->next;}
            ListNode *ln= new ListNode(t%10);
            if(!pp)pp=ans=ln;
            else {pp->next=ln;pp=ln;}
            t/=10;
        }
        if(t)pp->next = new ListNode(t);
        return ans;
    }
};

int main()
{
    Solution sol;
    ListNode l1(9),l2(9),l3(9),l4(9),l5(9),l6(9);
    //l1.next=&l2,l2.next=&l3;
    l4.next=&l5,l5.next=&l6;
    ListNode *ans=sol.addTwoNumbers(&l1,&l4);
	ListNode *p=ans;
    while(p){
        cout<<p->val;
        if(p->next)cout<<"->";
        p=p->next;
    }
    cout<<endl;
    return 0;
}
