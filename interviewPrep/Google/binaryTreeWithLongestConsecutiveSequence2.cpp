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
     int ans;
    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0, 0};
        auto [linc, ldec] = dfs(root->left);
        auto [rinc, rdec] = dfs(root->right);
        if (root->left) {
            if (root->val != root->left->val + 1) linc = 0;
            if (root->val != root->left->val - 1) ldec = 0;
        }
        if (root->right) {
            if (root->val != root->right->val + 1) rinc = 0;
            if (root->val != root->right->val - 1) rdec = 0;
        }
        ans = max({ ans, ldec + rinc + 1, rdec + linc + 1 });
        return { max(linc, rinc) + 1, max(ldec, rdec) + 1 };
    }
    int longestConsecutive2(TreeNode *root) {
        ans = 0;
        dfs(root);
        return ans;
        // write your code here
    }
};