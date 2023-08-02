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
    
    int kthSmallest(TreeNode* root, int k) {
        return findsmallest(root,k);
    }
    int findsmallest(TreeNode* root, int &k) {
        if(!root) return -1;
        int l = findsmallest(root->left,k);
        if(l!=-1) return l;
        k--;
        if(k==0)
            return root->val;
       return findsmallest(root->right,k);
    }
};