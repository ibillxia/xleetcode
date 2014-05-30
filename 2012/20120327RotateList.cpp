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
	ListNode* rotateRight(ListNode *head, int k) {
		if(!head||!head->next)return head;
		ListNode *ans,*p,*q;
		p=head;
		int n=0;
		while(p){
			n++;
			q=p;
			p=p->next;
		}
		k=k%n;
		if(k<1)return head;
		k=n-k;
		p=head;
		while(--k){
			p=p->next;
		}
		ans=p->next;
		q->next=head;
		p->next=NULL;
		return ans;
	}
};

int main()
{
	Solution sol;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5);
	l1.next=&l2,l2.next=&l3,l3.next=&l4,l4.next=&l5;
	ListNode *ans = sol.rotateRight(&l1,3);
	ListNode *p=ans;
	while(p){
		cout<<p->val<<"->";
		p=p->next;
	}
	cout<<"NULL"<<endl;
	return 0;
}

