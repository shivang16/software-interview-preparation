/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
map <int,int> sum;
void getSum(TreeNode* A,int level){
    if(!A) return;
    sum[level]+=A->val;
    getSum(A->left,level-1);
    getSum(A->right,level+1);
}
vector<int> Solution::verticalSum(TreeNode* A) {
    sum.clear();
    getSum(A,0);
    vector <int> ans;
    for(auto i:sum)
        ans.push_back(i.second);
    return ans;
}
