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

// definition for singly-linked list with a random pointer
struct RandomListNode{
	int label;
	RandomListNode *next,*random;
	RandomListNode(int x) : label(x),next(NULL),random(NULL) { }
};

class Solution {
public:
	RandomListNode* copyRandomList(RandomListNode *head){
		if(!head)return NULL;
		RandomListNode *p=head,*pp,*q,*qq;
		map<RandomListNode*,int> mp;
		vector<RandomListNode*> vc;
		// copy label and next pointer
		RandomListNode *ans = new RandomListNode(p->label);
		mp.insert(make_pair(head,0));
		vc.push_back(ans);
		pp=ans,p=p->next;
		int i=1;
		while(p){
			RandomListNode *rln = new RandomListNode(p->label);
			mp.insert(make_pair(p,i));
			vc.push_back(rln);
			pp->next=rln;
			pp=pp->next;
			p=p->next;
			i++;
		}
		pp->next=NULL;
		// copy random pointer
		p=head,q=ans;
		while(p){
			if(p->random){
				i=mp.find(p->random)->second;
				q->random=vc[i];
			}else{
				q->random=NULL;
			}
			p=p->next;
			q=q->next;
		}
		return ans;
	}

	RandomListNode* copyRandomList2(RandomListNode *head) {  // TLE
		if(!head)return NULL;
		RandomListNode *p=head,*pp,*q,*qq;
		// copy label and next pointer
		RandomListNode *ans = new RandomListNode(p->label);
		pp=ans,p=p->next;
		while(p){
			RandomListNode *rln = new RandomListNode(p->label);
			pp->next=rln;
			pp=pp->next;
			p=p->next;
		}
		pp->next=NULL;
		// copy random pointer
		p=head,q=ans;
		while(p){
			if(p->random){
				pp=head,qq=ans;
				while(pp&&pp!=p->random){
					pp=pp->next;
					qq=qq->next;
				}
				q->random=qq;
			}else{
				q->random=NULL;
			}
			p=p->next;
			q=q->next;
		}
		return ans;
	}

	void printRandomList(RandomListNode *head){
		RandomListNode *p=head;
		cout<<"add: "<<p<<" ";
		while(p){
			cout<<p->label;
			if(p->random)cout<<"("<<p->random->label<<")"<<"->";
			else cout<<"(NULL)->";
			p=p->next;
		}
		cout<<"NULL"<<endl;
	}
};

int main()
{
	Solution sol;
	RandomListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6);
	l1.next=&l2,l1.random=&l3;
	l2.next=&l3,l2.random=&l6;
	l3.next=&l4,l3.random=&l5;
	l4.next=&l5,l5.next=&l6;
	sol.printRandomList(&l1);
	RandomListNode *ans = sol.copyRandomList(&l1);
	sol.printRandomList(ans);
	return 0;
}

