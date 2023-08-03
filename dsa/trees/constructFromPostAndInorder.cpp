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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0 || inorder.size()==0) return NULL;
        int node = postorder[postorder.size()-1];
        int ind = find(inorder.begin(),inorder.end(),node)-inorder.begin();
        vector <int> left,right;
        for(int i=0;i<inorder.size();i++){
            if(i<ind)
                left.push_back(inorder[i]);
            else if(i>ind)
                right.push_back(inorder[i]);
        }
        TreeNode* newNode = new TreeNode(node);
        postorder.pop_back();
        newNode->right = buildTree(right,postorder);
        newNode->left = buildTree(left,postorder);
        return newNode;
    }
};