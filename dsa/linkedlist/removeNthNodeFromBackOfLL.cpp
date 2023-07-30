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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;
        ListNode* fast = head;
        while(n-->0){
            fast = fast->next;
        }
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        if(!prev){
            return head->next;
        }
        prev->next = slow->next;
        delete(slow);
        return head;

    }
};