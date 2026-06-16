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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* s = head;
        ListNode* f = head;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode* t = s->next;
        s->next = NULL;
        ListNode* pre = NULL;
        ListNode* n = NULL;
        while (t) {
            n = t->next;
            t->next = pre;
            pre = t;
            t = n;
        }
        f = head;
        s = pre;
        while (f && s) {
            ListNode* n1 = f->next;
            ListNode* n2 = s->next;
            f->next = s;
            s->next = n1;
            f = n1;
            s = n2;
        }
    }
};