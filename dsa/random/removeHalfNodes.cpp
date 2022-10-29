/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* removeHalf(TreeNode* A){
    if(!A) return A;
    if(!A->left && !A->right) return A;
    A->left = removeHalf(A->left);
    A->right = removeHalf(A->right);
    if(!A->left)
        return A->right;
    if(!A->right)
        return A->left;
    return A;
    
    
}
TreeNode* Solution::solve(TreeNode* A) {
    return removeHalf(A);
}