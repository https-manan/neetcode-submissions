/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* s=head;
        ListNode* f=head;
        ListNode*pre=nullptr;
        for(int i=0;i<n;i++){
            f=f->next;
        }
        if(f==nullptr)return head->next;
        while(f){
            pre=s;
            s=s->next;
            f=f->next;
        }
        pre->next=s->next;
        return head;
    }
};
