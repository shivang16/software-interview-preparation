// https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/description/
class Solution {
public:
    int m;
    int n;
    int ans;
    void flip(vector<vector<int>>& mat,int i,int j){
        mat[i][j]=!mat[i][j];
        if(i>0) mat[i-1][j]=!mat[i-1][j];
        if(j>0) mat[i][j-1]=!mat[i][j-1];
        if(i<m-1) mat[i+1][j]=!mat[i+1][j];
        if(j<n-1) mat[i][j+1]=!mat[i][j+1];
    }
    bool zeromat(vector<vector<int>>& mat){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j])return false;
            }
        }
        return true;
    }
    void backtrack(vector<vector<int>>& mat , int steps, int i, int j){
        if(j==n){
            j=0;
            i++;
        }
        if(i==m){
            if(zeromat(mat)) ans = min(steps,ans);
            return;
        }
        if((i>0 && j>0)&& mat[i-1][j-1]==1) return;
        backtrack(mat,steps,i,j+1);
        flip(mat,i,j);
        backtrack(mat,steps+1,i,j+1);
        flip(mat,i,j);
    }
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        if(m==1 && n==1)return mat[0][0];
        ans = INT_MAX;
        backtrack(mat,0,0,0);
        return ans==INT_MAX?-1:ans;
    }
};