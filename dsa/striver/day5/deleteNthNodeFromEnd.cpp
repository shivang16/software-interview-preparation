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
    ListNode* prev;
    ListNode* getNthNode(ListNode* head,int n){
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast!=NULL){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        return slow; 
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        prev = NULL;
        ListNode* temp = getNthNode(head,n);
        if(prev==NULL)
        {
            temp = head->next;
            delete(head);
            return temp;
        }
        prev->next = temp->next;
        delete(temp);
        return head;
        
    }
};