#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

//definition for singly-linked list.
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseKGroup(ListNode *head,int k) {
		//printList(head);
		if(k<2)return head;
		if(!head)return NULL;
		int i=k;
		ListNode *p,*q,*r,*t;
		p=head;
		while(--i&&p){
			p=p->next;
		}
		if(!p)return head;
		q=p->next;
		r=head;
		p=r->next;
		while(p!=q){
			t=p->next;
			p->next=r;
			r=p;
			p=t;
		}
		head->next=reverseKGroup(q,k);
		return r;
	}
	void printList(ListNode *head){
		ListNode *p=head;
		while(p){
			cout<<p->val<<"->";
			p=p->next;
		}
		cout<<"NULL"<<endl;
	}
};

int main()
{
	Solution sol;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7),l8(8),l9(9);
	l1.next=&l2;
	l2.next=&l3;
	l3.next=&l4;
	l4.next=&l5;
	l5.next=&l6;
	l6.next=&l7;
	l7.next=&l8;
	l8.next=&l9;
	sol.printList(&l1);
	ListNode *ans = sol.reverseKGroup(&l1,4);
	sol.printList(ans);
	return 0;
}

