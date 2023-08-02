/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

bool isParentSum(Node *root){
    if(!root) return true;
    if(!root->left && !root->right) return true;
    int sum = 0;
    if(root->left)
        sum+=root->left->data;
    if(root->right)
        sum+=root->right->data;
    return sum==root->data && isParentSum(root->left) && isParentSum(root->right);
    // Write your code here.
}