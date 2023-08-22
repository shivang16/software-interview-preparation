/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map <Node*,Node*> Mp;
        Node* temp = head;
        Node* head2 = NULL;
        Node* temp1 = NULL;
        while(temp){
            Node* nnode = new Node(temp->val);
            if(temp1==NULL){
                head2 = nnode;
            }else{
                temp1->next = nnode;
            }
            temp1 = nnode;
            Mp[temp] = nnode;
            temp = temp->next; 
        }temp1->next = nnode;
        temp1 = head2;
        temp = head;
        while(temp){
            temp1->random = temp->random?Mp[temp->random]:NULL;
            temp1 = temp1->next;
            temp = temp->next;
        }
        return head2;
    }
};