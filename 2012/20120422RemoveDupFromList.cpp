/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)return NULL;
        ListNode *p=head,*q;
        while(p){
            while(p->next && p->val==p->next->val){
                q=p->next;
                p->next=q->next;
                free(q);
            }
            p=p->next;
        }
        return head;
    }
};