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
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    map <int,vector <int>> H;
    int height(TreeNode* root){
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        int ht = 1+max(l,r);
        H[ht].push_back(root->val);
        return ht;
    }
    vector<vector<int>> findLeaves(TreeNode * root) {
        height(root);
        vector <vector <int>> ans;
        for(auto i:H)
            ans.push_back(i.second);
        return ans;
        // write your code here
    }
};