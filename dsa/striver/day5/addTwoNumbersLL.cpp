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
    
    ListNode* head;
    int getSize(ListNode* l){
        if(!l) return 0;
        int n = 0;
        ListNode* temp = l;
        while(temp){
            n++;
            temp = temp->next;
        }
        return n;
    }
    void getAns(ListNode* l1,ListNode* l2,int carry,ListNode* crnt){
        if(l1==NULL)
        {
            if(carry!=0)
                crnt->next = new ListNode(carry);
            return;
        }
        ListNode* nl1 = l1->next;
        int v1 = l1->val;
        int v2 = l2==NULL?0:l2->val;
        int sum = v1+v2+carry;
        int val = sum%10;
        carry = sum/10;
        ListNode* temp = new ListNode(val);
        if(head==NULL){
            head = temp;
        }else{
            crnt->next = temp;
        }
        crnt = temp;
        if(l2)
            return getAns(l1->next,l2->next,carry,crnt);
        else
            return getAns(l1->next,l2,carry,crnt);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = getSize(l1);
        int n2 = getSize(l2);
        if(n2>n1)
            swap(l1,l2);
        int carry = 0;
        head = NULL;
        getAns(l1,l2,carry,head);
        return head;
    }
};