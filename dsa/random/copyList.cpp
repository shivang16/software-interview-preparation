// https://www.interviewbit.com/problems/copy-list/
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(!A) return NULL;
    
    RandomListNode* temp = A;
    RandomListNode* head = new RandomListNode(A->label);
    RandomListNode* itr = head; 
    unordered_map <RandomListNode*,RandomListNode*> M;
    M[NULL] = NULL;
    M[A] = head;
    temp = temp->next;
    while(temp){
        itr->next = new RandomListNode(temp->label);
        itr = itr->next;
        M[temp] = itr;
        temp = temp->next;
    }
    temp = A;
    itr = head;
    while(itr){
        itr->random = M[A->random];
        itr = itr->next;
        A = A->next;
    }
    return head;
}
