// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector <vector <int>> dp(m,vector <int> (n,0));
        bool flag = false;
        for(int i=0;i<m;i++){
            if(flag)
                dp[i][0] = 0;
            else{
                if(mat[i][0]==1){
                    dp[i][0] = 0;
                    flag = true;
                }else{
                    dp[i][0] = 1;
                }
            }
        }
        flag = false;
        for(int i=0;i<n;i++){
            if(flag)
                dp[0][i] = 0;
            else{
                if(mat[0][i]==1){
                    dp[0][i] = 0;
                    flag = true;
                }else{
                    dp[0][i] = 1;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]==0){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }else
                    dp[i][j] = 0;
            }
        }

        // for(auto i:dp){
        //     for(auto j:i)
        //         cout << j << " ";
        //     cout << endl;
        // }
        return dp[m-1][n-1];
    }
};