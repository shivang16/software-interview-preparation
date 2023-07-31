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
    int getLength(ListNode* head){
        int l = 0;
        ListNode* temp = head;
        while(temp){
            l++;
            temp = temp->next;
        }
        return l;
    }
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* now = head;
        ListNode* nxt = head->next;
        while(now->next){
            now->next = prev;
            prev = now;
            now = nxt;
            nxt = nxt->next;
        }
        now->next = prev;
        return now;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* temp = head;
        ListNode* prev;
        for(int i=0;i<k;i++){
            if(temp==NULL){
                return head;
            } 
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        ListNode* newHead = reverse(head);
        head->next = reverseKGroup(temp,k);
        return newHead;
    };
};