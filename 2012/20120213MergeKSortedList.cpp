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
	ListNode* mergeKLists(vector<ListNode *> &lists) {
		ListNode *ans = NULL;
		int i,mi;
		for(i=0;i<lists.size()&&lists.size();i++){
			if(!lists[i]){
				lists[i]=lists[lists.size()-1];
				lists.pop_back();
				i--;
			}
		}
		if(!lists.size())return ans;
		if(lists.size()==1)return ans=lists[0];
		ListNode *p=NULL;
		while(1){
			mi=0;
			for(i=1;i<lists.size();i++){ // find minimum
				if(lists[i]->val < lists[mi]->val){
					mi=i;
				}
			}
			//cout<<mi<<" "<<lists[mi]->val<<endl;
			if(!p){
				ans=p=lists[mi];
			}else{
				p->next=lists[mi];
				p=p->next;
			}
			if(lists[mi]->next){
				lists[mi]=lists[mi]->next;
			}else{ // last one in lists[mi]
				lists[mi]=lists[lists.size()-1];
				lists.pop_back();
			}
			if(lists.size()==1){
				p->next=lists[0];
				break;
			}
			//printListVec(lists);
			//getchar();
		}
		return ans;
	}

	void printListVec(vector<ListNode *> &lists){
		ListNode *p;
		for(int i=0;i<lists.size();i++){
			p=lists[i];
			while(p){
				cout<<p->val<<"->";
				p=p->next;
			}
			cout<<"NULL"<<endl;
		}
	}
};

int main()
{
	Solution sol;
	ListNode l11(1),l12(3),l13(5),l21(2),l22(4),l23(8),l31(1),l32(5),l33(7);
	l11.next=&l12,l12.next=&l13;
	l21.next=&l22,l22.next=&l23;
	l31.next=&l32,l32.next=&l33;
	vector<ListNode *> lists;
	//lists.push_back(&l11);
	//lists.push_back(&l21);
	//lists.push_back(&l31);
	lists.push_back(NULL);
	lists.push_back(NULL);
	sol.printListVec(lists);
	ListNode* ans = sol.mergeKLists(lists);
	ListNode* p=ans;
	while(p){
		cout<<p->val<<"->";
		p=p->next;
	}
	cout<<"NULL"<<endl;
	return 0;
}

