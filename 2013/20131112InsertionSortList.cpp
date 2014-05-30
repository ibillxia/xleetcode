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

// definition of singly-linked list
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode *head) {
		ListNode* ans=head;
		if(!head||!head->next) return ans;
		ListNode *p,*pp,*q,*pq;
		pp=head,p=head->next;
		while(p){
			if(p->val >= pp->val){ // already ascend
				pp=p;
				p=p->next;
			}else{
				pp->next=p->next;
				q=head,pq=NULL;
				while(q->val < p->val){ // find insertion point
					pq=q;
					q=q->next;
				}
				if(!pq){ // insert before head
					p->next=head;
					ans=head=p;
				}else{ // insert between node pq and q
					p->next=q;
					pq->next=p;
				}
				p=pp->next;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	ListNode l1(2),l2(1),l3(5),l4(6),l5(4),l6(3);
	l1.next=&l2;
	l2.next=&l3,l3.next=&l4,l4.next=&l5,l5.next=&l6;
	ListNode* ans=sol.insertionSortList(&l1);
	ListNode* p=ans;
	while(p){
		cout<<p->val<<"->";
		p=p->next;
	}
	cout<<"NULL"<<endl;
	return 0;
}

