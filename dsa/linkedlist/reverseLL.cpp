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
        ListNode* crnt = head;
        ListNode* prev = NULL;
        ListNode* nxt = head->next;
        while(crnt->next){
            crnt->next = prev;
            prev = crnt;
            crnt = nxt;
            nxt = nxt->next;
        }
        crnt->next = prev;
        return crnt;
    }
};