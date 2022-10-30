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
    long long sol(TreeNode* root,long long sum){
        if(!root) return 0;
        return sol(root->left,sum-root->val)+sol(root->right,sum-root->val)+(root->val==sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while(!Q.empty()){
            TreeNode* tp = Q.front();
            Q.pop();
            ans+=sol(tp,targetSum);
            if(tp->left)
                Q.push(tp->left);
            if(tp->right)
                Q.push(tp->right);
        }
        return ans;
    }
};