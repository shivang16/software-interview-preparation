/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool hasPath(TreeNode* A,int &B){
    if(!A) return false;
    if(A->left==NULL && A->right==NULL && A->val==B) return true;
    B-=A->val;
    bool l = hasPath(A->left,B);
    bool r = hasPath(A->right,B);
    B+=A->val;
    return l||r; 
}
int Solution::hasPathSum(TreeNode* A, int B) {
    return hasPath(A,B);
}
