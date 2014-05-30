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

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode *head) {
		if(!head||!head->next)return;
		int len=0;
		ListNode *p=head,*q,*r;
		while(p){ // cal length of list
			len++;
			p=p->next;
		}

		// reverse the second half of the list
		len=(len>>1)+(len&0x1 ? 1:0);
		p=head;
		while(--len)p=p->next;
		q=p->next;
		p->next=NULL;
		//printList(q);
		q=reverseList(q);
		//printList(q);

		// merge the two halfs
		p=head;
		while(q){
			r=p->next;
			p->next=q;
			q=q->next;
			p->next->next=r;
			p=r;
		}
		return;
	}

	ListNode *reverseList(ListNode *head){
		if(!head||!head->next)return head;
		ListNode *p,*q,*r;
		p=head;
		q=p->next;
		p->next=NULL;
		while(q){
			r=q->next;
			q->next=p;
			p=q;
			q=r;
		}
		return p;
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
	ListNode l1(1),l2(2),l3(3),l4(4);
	l1.next=&l2;
	l2.next=&l3;
	l3.next=&l4;
	sol.reorderList(&l1);
	sol.printList(&l1);
	return 0;
}

