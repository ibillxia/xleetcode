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

// Definition for singly-linked list
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if(!head) return NULL;
		if(head->next==head) return head;
		ListNode *slow,*fast,*ans;
		slow=fast=head;
		while(1){
			if(slow->next)slow=slow->next;
			else return NULL;
			if(fast->next&&fast->next->next)fast=fast->next->next;
			else return NULL;
			if(fast==slow)break;
		}
		fast=head;
		while(fast!=slow){
			fast=fast->next;
			slow=slow->next;
		}
		return fast;
	}
};

int main()
{
	Solution sol;
	ListNode *ans,l1(1),l2(2),l3(3),l4(4),l5(5);
	l1.next=&l2;
	l2.next=&l3;
	l3.next=&l4;
	l4.next=&l5;
	l5.next=&l1;
	ans=sol.detectCycle(&l1);
	cout<<ans->val<<endl;
	return 0;
}

