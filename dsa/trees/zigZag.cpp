/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int>> ans;
        bool dir = true;
        stack <TreeNode*> S;
        if(!root) return ans;
        S.push(root);
        queue <TreeNode*> Q;
        while(!S.empty()){
            vector <int> temp;
            while(!S.empty()){
                TreeNode* node = S.top();
                S.pop();
                temp.push_back(node->val);
                if(dir){
                    if(node->left)
                        Q.push(node->left);
                    if(node->right)
                        Q.push(node->right);
                }else{
                    if(node->right)
                        Q.push(node->right);
                    if(node->left)
                        Q.push(node->left);
                }
            }
            dir = !dir;
            while(!Q.empty()){
                S.push(Q.front());
                Q.pop();
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};