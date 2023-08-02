/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue <Node*> Q;
        if(!root) return root;
        Q.push(root);
        while(!Q.empty()){
            int sz = Q.size();
            int i = 0;
            Node* crnt;
            while(i<sz){
                crnt = Q.front();
                Q.pop();
                if(i!=sz-1)
                    crnt->next = Q.front();
                if(crnt->left)
                    Q.push(crnt->left);
                if(crnt->right)
                   Q.push(crnt->right);
                i++;
            }
        }
        return root;
    }
};