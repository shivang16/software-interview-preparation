/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* mergeList(Node* list1, Node* list2){
	Node* temp1 = list1;
	Node* temp2 = list2;
	Node* ans = list1;
	ans->next = NULL;
	while(temp1 && temp2){
		if(temp1->data > temp2->data){
			ans->next = temp2;
			temp2 = temp2->child;
		}else{
			ans->next = temp1;
			temp1 = temp1->child;
		}
		ans = ans->next;
	}
	while(temp1){
		ans->next = temp1;
		temp1 = temp1->child;
		ans = ans->next;
	}
	while(temp2){
		ans->next = temp2;
		temp2 = temp2->child;
		ans = ans->next;
	}
	
	return list1;
}
Node* flattenLinkedList(Node* head) 
{
	if(!head || !head->next) return head;
	head->next = flattenLinkedList(head->next);
	head = mergeList(head,head->next);
	return head;
	// Write your code here
}
