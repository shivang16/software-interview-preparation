class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i == 0 || j == 0 || i == n-1 || j == m-1 && grid[i][j] == 0) // for corner zeros
                {
                    dfs(i,j,grid);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
    private:
    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 0)
        {
            return;
        }
        grid[i][j] = -1;
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
    }
};