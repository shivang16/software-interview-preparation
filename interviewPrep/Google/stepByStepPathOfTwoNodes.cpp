// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another
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
    TreeNode* findLca(TreeNode* root,int val1,int val2){
        if(!root) return root;
        if(root->val==val1 || root->val==val2) return root;
        TreeNode* l = findLca(root->left,val1,val2);
        TreeNode* r = findLca(root->right,val1,val2);
        if(l && r) return root;
        if(l) return l;
        if(r) return r;
        return NULL;
    }

    TreeNode* findNode(TreeNode* root,int node,string &s){
        if(!root) return NULL;
        if(root->val==node) return root;
        TreeNode* l = findNode(root->left,node,s);
        TreeNode* r = findNode(root->right,node,s);
        if(l){
            s+='L';
            return l;
        }
        if(r){
            s+='R';
            return r;
        }
        return NULL;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLca(root,startValue,destValue);
        string ans = "";
        if(lca->val==startValue){
            findNode(lca,destValue,ans);
            reverse(ans.begin(),ans.end());
        }else if(lca->val==destValue){
            findNode(lca,startValue,ans);
            for(int i=0;i<ans.size();i++)
                ans[i] = 'U';
            //Go up
        }else{
            findNode(lca,startValue,ans);
            for(int i=0;i<ans.size();i++)
                ans[i] = 'U';
            string temp = "";
            findNode(lca,destValue,temp);
            reverse(temp.begin(),temp.end());
            ans+=temp;
            //First go up
            //Go down
        }
        return ans;
    }
};