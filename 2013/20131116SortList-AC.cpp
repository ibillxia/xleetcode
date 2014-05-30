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
		// test if begin through end are the same
		ListNode *p=begin,*q;
		q=p->next;
		while(q){
			if(q->val!=p->val||q==end)break;
			q=q->next;
		}
		if(!q||q->val==p->val)return;

		float val=(p->val+q->val)/2.0;
		//cout<<val<<":";printList(begin,end);
		p = partition(begin,end,val);
		//cout<<val<<":";printList(begin,end);
		if(p){
			quickSort(begin,p);
			quickSort(p,end);
		}
	}

	ListNode *partition(ListNode *p1,ListNode *p2,float val){
		ListNode *p,*q;
		p=NULL,q=p1;
		while(q!=p2)
		{
			if(q->val >val){ // larger than val, add to list q
				if(!p)p=q;
			}else{ // smaller or equal to val, add to list p
				if(p){
					swap(p->val,q->val);
					p=p->next;
				}
			}
			q=q->next;
		}
		return p;
	}

	void printList(ListNode *head,ListNode *tail=NULL){
		ListNode *p=head;
		while(p!=tail){
			cout<<p->val;
			if(p->next!=tail)cout<<",";
			p=p->next;
		}
		cout<<endl;
	}
};

int main()
{
	Solution sol;
	ListNode *ans;
	
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
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
	sol.printList(lh);
	ans = sol.sortList(lh);
	sol.printList(ans);
	return 0;
}

