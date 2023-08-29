class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& a) {
        int n = a.size(),m=a[0].size();
        map<int, vector<pair<int,int>>> unique;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                unique[a[i][j]].push_back({i,j});
        vector<vector<int>> dp(n,vector<int>(m,1));
        vector<int> row(n,0),col(m,0);
        int ans = 0;
        for(auto x:unique)
        {
            //Unique elements
            for(auto y : x.second)
            {
                int a = y.first;
                int b = y.second;
                dp[a][b] = max(dp[a][b], max(row[a],col[b])+1);    
                ans = max(ans,dp[a][b]);
            }
            //Updating the row and col max
            for(auto y : x.second)
            {
                int a = y.first;
                int b = y.second;
                row[a] = max(row[a],dp[a][b]);
                col[b] = max(col[b],dp[a][b]);    
            }
        }
        return ans;
    }
};