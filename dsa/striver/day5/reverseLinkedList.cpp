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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p = NULL;
        ListNode* c = head;
        ListNode* n = head->next;
        while(c->next){
            c->next = p;
            p = c;
            c = n;
            n = n->next;
        }
        c->next = p;
        return c;
    }
};