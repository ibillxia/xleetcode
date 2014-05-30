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

// definition for singly-linked list
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode *head,int x) {
		ListNode *ans=NULL,*p,*pp,*q;
		if(!head) return ans;
		ans=p=head,pp=NULL;
		while(p&&p->val<x){ // find partition point pp
			pp=p;
			p=p->next;
		}
		if(p){ // p->val >= x
			q=p;
			p=p->next;
		}
		while(p){
			if(p->val<x){
				q->next=p->next;
				if(!pp){
					ans=pp=p;
					pp->next=head;
				}else{
					p->next=pp->next;
					pp->next=p;
					pp=p;
				}
				p=q->next;
			}else{
				q=p;
				p=p->next;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	ListNode l1(5),l2(4),l3(3),l4(2),l5(5),l6(2);
	l1.next=&l2,l2.next=&l3,l3.next=&l4,l4.next=&l5,l5.next=&l6;
	ListNode *ans = sol.partition(&l1,4);
	ListNode *p=ans;
	while(p){
		cout<<p->val;
		if(p->next)cout<<"->";
		p=p->next;
	}
	cout<<endl;
	return 0;
}

