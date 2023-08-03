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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0) return NULL;
        int node = preorder[0];
        int ind = find(inorder.begin(),inorder.end(),node)-inorder.begin();
        vector <int> left,right;
        for(int i=0;i<inorder.size();i++){
            if(i<ind)
                left.push_back(inorder[i]);
            else if(i>ind)
                right.push_back(inorder[i]);
        }
        TreeNode* newNode = new TreeNode(node);
        preorder.erase(preorder.begin());
        newNode->left = buildTree(preorder,left);
        newNode->right = buildTree(preorder,right);
        
        return newNode;
    }
};