// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/submissions/1040082182/
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
    map <int,vector <int>> adj;
    void createAdj(TreeNode* root,int prev){
        if(!root) return;
        
        if(root->left){
            createAdj(root->left,root->val);
            adj[root->val].push_back(root->left->val);
        }
        
        if(prev!=-1)
            adj[root->val].push_back(prev);
        
        if(root->right){
            createAdj(root->right,root->val);
            adj[root->val].push_back(root->right->val);
        }
        
    }

    int amountOfTime(TreeNode* root, int start) {
        createAdj(root,-1);    
        queue <int> Q;
        unordered_map <int,bool> vis;
        Q.push(start);
        vis[start] = true;
        int time = 0;
        while(!Q.empty()){
            int sz = Q.size();
            while(sz--){
                int u = Q.front();
                Q.pop();
                for(auto v:adj[u]){
                    if(vis.count(v)==0){
                        vis[v] = true;
                        Q.push(v);
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};