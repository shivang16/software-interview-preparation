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
    int len(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n = len(head);
        k = k%n;
        if(k==0) return head;
        int shift = n-k;
        ListNode* temp = head;
        ListNode* prev;
        while(shift-->0) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        ListNode* newHead = temp;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        return newHead;

    }
};