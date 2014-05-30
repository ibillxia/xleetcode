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
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode*head,int m,int n) {
		ListNode *ans=head;
		if(m==n)return ans;
		//if(!head->next->next){ // m=1,n=2,two nodes
		//	ans=head->next;
		//	head->next->next=head;
		//	head->next=NULL;
		//	return ans;
		//}
		// m<n,more than 2 nodes
		ListNode *p,*pp,*sp;
		p=pp=sp=head;
		n-=m;
		if(m>1){ // start point is not head
			while(--m&&p){ // find start point sp=p
				pp=p;
				p=p->next;
			}
		}
		sp=p;
		p=p->next;
		while(n--&&p){
			sp->next=p->next;
			if(!m){ // not start from head
				p->next=pp->next;
				pp->next=p;
			}else { // start from head
				p->next=pp;
				pp=p;
			}
			p=sp->next;
		}
		if(m)ans=pp;
		return ans;
	}
};

int main()
{
	Solution sol;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5);
	l1.next=&l2;
	//l2.next=&l3;
	//l3.next=&l4,l4.next=&l5;
	ListNode *ans=sol.reverseBetween(&l1,1,2); // 2,3; 1,3
	ListNode *p=ans;
	while(p){
		cout<<p->val;
		if(p->next)cout<<"->";
		p=p->next;
	}
	cout<<"->NULL"<<endl;
	return 0;
}

