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
    int len(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = len(headA);
        int n2 = len(headB);
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        if(n2>n1){
            swap(t1,t2);
            swap(n1,n2);
        }
        int diff = n1-n2;
        while(diff-->0) t1 = t1->next;
        while(t1 && t2){
            if(t1==t2)
                return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;


    }
};