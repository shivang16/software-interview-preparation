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
        ListNode* head = NULL;
        ListNode* t;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1!=NULL && temp2!=NULL){
            ListNode* temp = new ListNode();
            if(temp1->val > temp2->val){
                temp->val = temp2->val;
                temp2 = temp2->next;
            }else{
                temp->val = temp1->val;
                temp1 = temp1->next;
            }
            if(head==NULL){
                head = temp;
            }else{
                t->next = temp;
            }
            t = temp;
        }
        while(temp1!=NULL){
            ListNode* temp = new ListNode(temp1->val);
            temp1 = temp1->next;
            if(head==NULL){
                head = temp;
            }else{
                t->next = temp;
            }
            t = temp;
        }
        while(temp2!=NULL){
            ListNode* temp = new ListNode(temp2->val);
            temp2 = temp2->next;
            if(head==NULL){
                head = temp;
            }else{
                t->next = temp;
            }
            t = temp;
        }
        return head;
    }
};