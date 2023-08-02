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
    bool isLeaf(TreeNode* root){
        return root->left==NULL && root->right==NULL;
    }
    void findPaths(TreeNode* root,vector <vector <int>> &paths,vector <int> &temp){
        if(!root) return;
        if(isLeaf(root)){
            temp.push_back(root->val);
            paths.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        findPaths(root->left,paths,temp);
        findPaths(root->right,paths,temp);
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <vector <int>> paths;
        vector <int> temp;
        findPaths(root,paths,temp);
        vector <string> ans;
        for(auto i:paths){
            string s = "";
            for(int j=0;j<i.size();j++){
                if(j==0)
                    s = to_string(i[j]);
                else
                    s = s+"->"+to_string(i[j]);
            }
            ans.push_back(s);
        }
        return ans;
    }
};