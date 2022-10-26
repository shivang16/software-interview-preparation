/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int getSize(ListNode* A){
     if(!A) return 0;
     int count = 0;
     ListNode* temp = A;
     while(temp){
         count++;
         temp = temp->next;
     }
     return count;
 }
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int size = getSize(A);
    B = B%size;
    if(B==0) return A;
    int ro = size-B;
    ListNode* temp = A;
    ListNode* prev = NULL;
    for(int i=0;i<ro;i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    prev = temp;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = A;
    return prev;
    
}
