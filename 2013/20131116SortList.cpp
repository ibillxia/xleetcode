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
#include <cstdlib>

// definition of singly-linked list
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode *head) { // use the algorithm of QuikSort
		if(!head || !head->next) return head;
		quickSort(head,NULL);
		return head;
	}

	void quickSort(ListNode *begin,ListNode *end){
		if(!begin||!begin->next||begin==end)return;
		ListNode *p=begin,*q;
		q=p->next;
		while(q&&q!=end){
			if(q->val!=p->val)break;
			q=q->next;
		}
		if(!q||(end&&q->val==end->val))return;

		float val=p->val/2.0+0.3;
		//cout<<val<<",";
		p = partition(begin,end,val);
		if(p){
			//printList(begin,end);
			quickSort(begin,p);
			quickSort(p,end);
		}
	}

	ListNode *partition(ListNode *p1,ListNode *p2,float val){
		ListNode *p,*ph,*q,*qh,*r,*t;
		p=ph=q=qh=NULL,r=p1;
		while(r!=p2){
			if(r->val >val){
				if(!q)qh=q=r;
				else {
					q->next=r;
					q=r;
				}
			}else{
				if(!p)ph=p=r;
				else {
					p->next=r;
					p=r;
				}
			}
			t=r->next;
			r->next=NULL;
			r=t;
		}
		if(p&&qh)p->next=qh;
		if(q)q->next=p2;
		else p->next=p2;
		if(p)return p;
		return q;
	}

	void quickSort2(ListNode *begin,ListNode *end){  // TLE
		if(!begin)return;
		ListNode *p=begin,*q;
		q=p->next;
		while(q&&q!=end){
			if(q->val!=p->val)break;
			q=q->next;
		}
		if(q==end)return;
		p = partition(begin,end);
		if(p){
			cout<<p->val<<": ";
			printList(begin,end);
			quickSort(begin,p);
			quickSort(p->next,end);
		}
	}

	ListNode *partition(ListNode *p1,ListNode *p2){
		if(!p1||!p1->next||p1==p2)return NULL;
		int pv=p1->val;
		ListNode *p,*q,*qh,*r,*t;
		p=p1,q=qh=NULL,r=p1->next;
		while(r!=p2){
			if(r->val >pv){
				if(!q)qh=q=r;
				else {
					q->next=r;
					q=r;
				}
			}else{
				p->next=r;
				p=r;
			}
			t=r->next;
			r->next=NULL;
			r=t;
		}
		if(qh)p->next=qh;
		if(q)q->next=p2;
		else p->next=p2;
		swap(p1->val,p->val);
		return p;
	}

	void printList(ListNode *head,ListNode *tail=NULL){
		ListNode *p=head;
		while(p!=tail){
			cout<<p->val<<"->";
			p=p->next;
		}
		if(!tail)cout<<"NULL";
		cout<<endl;
	}
};

int main()
{
	Solution sol;
	ListNode *ans;
/*	ListNode l1(3),l2(3),l3(2),l4(2),l5(3),l6(3);
	l1.next=&l2;
	l2.next=&l3;
	l3.next=&l4,l4.next=&l5,l5.next=&l6;
	*ans = sol.sortList(&l1);
	ListNode *p=ans;
	cout<<"ans: ";
	while(p){
		cout<<p->val<<"->";
		p=p->next;
	}
	cout<<"NULL"<<endl;
*/	
	//freopen("test.in","r",stdin);
	ListNode *lh=NULL,*lp;
	int n;
	while(~scanf("%d%*c",&n)){
		ListNode *ln = new ListNode(n);
		if(!lh)lh=lp=ln;
		else {
			lp->next=ln;
			lp=ln;
		}
	}
	//sol.printList(lh);
	//freopen("test.out","w",stdout);
	ans = sol.sortList(lh);
	sol.printList(ans);
	return 0;
}

