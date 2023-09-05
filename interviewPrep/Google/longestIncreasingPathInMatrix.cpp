// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description
class Solution {
public:
    int n,m;
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,-1,1};
    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }

    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& dp,int x,int y,int &ans){
        if(dp[x][y]!=-1) return dp[x][y];
        dp[x][y] = 1;
        for(int i=0;i<4;i++){
            int nX = x+X[i];
            int nY = y+Y[i];
            if(isValid(nX,nY)){
                // cout << nX << " " << nY << endl;
                if(matrix[x][y]<matrix[nX][nY]){
                    dp[x][y] = max(dp[x][y],1+dfs(matrix,dp,nX,nY,ans));
                }
            }
        }
        ans = max(ans,dp[x][y]);
        return dp[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(),n=matrix[0].size();
        vector <vector <int>> dp(m,vector <int> (n,-1));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1)
                    dfs(matrix,dp,i,j,ans);
            }
        }
        return ans;    
    }
};