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
    int getSum(TreeNode* root,int &ans){
        if(!root) return 0;
        int ls = max(0,getSum(root->left,ans));
        int rs = max(0,getSum(root->right,ans));
        ans = max(ans,rs+ls+root->val);
        return root->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        int ans = -10000;
        getSum(root,ans);
        return ans;
    }
};