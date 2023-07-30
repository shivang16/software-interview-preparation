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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* l3;
        ListNode* head; 
        while(l1 && l2){
            ListNode* temp;
            if(l1->val > l2->val){
                temp = l2;
                l2 = l2->next;
            }else{
                temp = l1;
                l1 = l1->next;
            }
            if(!l3){
                l3 = temp;
                head = l3;
            }else{
                l3->next = temp;
                l3 = l3->next;
            }
        }
        while(l1){
            l3->next = l1;
            l1 = l1->next;
            l3 = l3->next;
        }
        while(l2){
            l3->next = l2;
            l2 = l2->next;
            l3 = l3->next;
        }
        return head;
    }
};