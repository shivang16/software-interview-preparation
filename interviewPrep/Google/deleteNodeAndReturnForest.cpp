// https://leetcode.com/problems/delete-nodes-and-return-forest/submissions/
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
    unordered_set <int> toDelete;
    TreeNode* getAns(TreeNode* crnt,TreeNode* prevRoot,unordered_set <TreeNode*> &ans){
        if(!crnt) return NULL;
        if(toDelete.find(crnt->val)==toDelete.end()){
            crnt->left = getAns(crnt->left,prevRoot,ans);
            crnt->right = getAns(crnt->right,prevRoot,ans);
        }else{
            if(crnt->left==NULL && crnt->right==NULL){
                delete(crnt);
                return NULL;
            }
            cout << crnt->val << " " << prevRoot->val << endl;
            TreeNode* left = crnt->left;
            TreeNode* right = crnt->right;
            delete(crnt);
            getAns(left,left,ans);
            getAns(right,right,ans);
            return NULL;
        }
        ans.insert(prevRoot);
        return crnt;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto i:to_delete)
            toDelete.insert(i);
        unordered_set <TreeNode*> ans;
        getAns(root,root,ans);

        vector <TreeNode*> finalAns;
        for(auto i:ans){
            finalAns.push_back(i);
        }
        return finalAns;
    }
};