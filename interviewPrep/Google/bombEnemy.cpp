// https://www.lintcode.com/problem/553/description
class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int m,n;
    vector <vector <int>> dp;
    int enemyCount = 0;
    void update(vector <vector <char>>& grid,int x,int y){
        if(grid[x][y]=='E'){
            enemyCount++;
        }else if(grid[x][y]=='0'){
            dp[x][y]+= enemyCount;
        }else{
            enemyCount = 0;
        }
    }
    int maxKilledEnemies(vector<vector<char>> &grid) {
        // write your code here
        if(!grid.size() || !grid[0].size()) return 0;
        int m = grid.size(), n = grid[0].size();
        dp.resize(m,vector <int> (n,0));
        for(int i=0;i<m;i++){
            enemyCount = 0;
            for(int j=0;j<n;j++) update(grid,i,j);
            enemyCount = 0;
            for(int j=n-1;j>=0;j--) update(grid,i,j);
        }
        for(int j=0;j<n;j++){
            enemyCount = 0;
            for(int i=0;i<m;i++) update(grid,i,j);
            enemyCount = 0;
            for(int i=m-1;i>=0;i--) update(grid,i,j);
        }
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                ans = max(ans,dp[i][j]);
        return ans;
    }
};