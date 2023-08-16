// https://leetcode.com/problems/find-duplicate-subtrees/description/
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
    vector <TreeNode*> ans;
    unordered_map <string,int> Mp;
    string dfs(TreeNode* root){
        if(!root) return "";
        string s = "";
        s+=to_string(root->val);
        s+="#";
        s+=dfs(root->left);
        s+="#";
        s+=dfs(root->right);
        if(Mp[s]==1)
            ans.push_back(root);
        Mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};