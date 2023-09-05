// https://www.lintcode.com/problem/595/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int getPath(TreeNode* root,int &ans){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int lf = getPath(root->left,ans);
        int rf = getPath(root->right,ans);
        bool hasGreater = false;
        if(root->left && root->val+1==root->left->val){
            lf++;
            hasGreater = true;
        }
        if(root->right && root->val+1 == root->right->val){
            hasGreater = true;
            rf++;
        }
        ans = max(ans,(lf,rf));
        return hasGreater?max(lf,rf):1;
    }
    int longestConsecutive(TreeNode *root) {
        // write your code here
        int ans = 0;
        getPath(root,ans);
        return ans;
        // return aens;
    }
};
