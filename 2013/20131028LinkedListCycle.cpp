#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        if(head->next==head)return true;
        ListNode *slow,*fast;
        slow=fast=head;
        while(1){
            if(slow->next)slow=slow->next;
            else break;
            if(fast->next&&fast->next->next)fast=fast->next->next;
            else break;
            if(slow==fast)return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    ListNode n1(1),n2(2),n3(3);
    n1.next=&n2,n2.next=&n3;//n3.next=&n2;
    bool ans = sol.hasCycle(&n1);
    cout<<ans<<endl;
	return 0;
}
