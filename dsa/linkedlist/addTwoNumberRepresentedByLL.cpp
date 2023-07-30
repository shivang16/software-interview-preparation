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
    int findLen(ListNode* list){
        int len = 0;
        ListNode* temp = list;
        while(!temp){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = findLen(l1);
        int len2 = findLen(l2);
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        if(len2>len1){
            n1 = l2;
            n2 = l1;
        }
        int carry = 0;
        ListNode* head;
        ListNode* ptr = NULL;
        while(n1 && n2){
            int sum = n1->val+n2->val+carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* node = new ListNode(digit);
            if(ptr){
                ptr->next = node;
                ptr = node;
            }else{
                head = node;
                ptr = node;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        while(n1){
            int sum = n1->val+carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* node = new ListNode(digit);
            ptr->next = node;
            ptr = node;
            n1 = n1->next;
        }
        while(n2){
            int sum = n2->val+carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* node = new ListNode(digit);
            ptr->next = node;
            ptr = node;
            n2 = n2->next;
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            ptr->next = node;
        }
        return head;
    }
};