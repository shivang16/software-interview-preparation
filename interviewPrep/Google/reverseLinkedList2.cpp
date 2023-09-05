// https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        if(left==right) return head;
        
        
        ListNode* prev = NULL;
        ListNode* now = head;
        ListNode* nxt = head->next;
        int i=0;
        for(;i<left-1;i++){
            prev = now;
            now = nxt;
            nxt = nxt->next;
        }
        ListNode* L = prev;
        ListNode* R = now;
        // cout << L->val << " " << R->val << " " << now->val << endl;
        prev = NULL;
        while(i<right-1){
            now->next = prev;
            prev = now;
            now = nxt;
            nxt = nxt->next;
            // cout << i << " " << prev->val <<" " <<now->val << " " << nxt->val << endl;
            i++;
        }
        now->next = prev;
        // cout << "--------\n";
        // cout << prev->val << " " << now->val << " " << nxt->val << endl;
        // cout << R->val << " " << L->val << endl;
        if(left!=1){
            L->next = now;
        }else{
            head = now;
        }
        R->next = nxt;
        // ListNode* temp = head;
        // while(!temp){
        //     cout << temp->val << " ";
        //     temp = temp->next;
        // }
        return head;
    }
};