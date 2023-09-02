class Solution {
public:
    int n,m;
    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    vector <vector <bool>> vis;

    void dfs(vector<vector <int>> & grid,int x,int y){
        vis[x][y] = true;
        for(int i=0;i<4;i++){
            int nx = x+X[i], ny = y+Y[i];
            if(isValid(nx,ny) && grid[nx][ny]==1 && !vis[nx][ny])
                dfs(grid,nx,ny);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vis.resize(m,(vector <bool> (n,false)));
        int count = 0;
        for(int i=0;i<m;i++){
            if(grid[i][0] && !vis[i][0])
                dfs(grid,i,0);
            if(grid[i][n-1] && !vis[i][n-1])
                dfs(grid,i,n-1);
        }
        for(int i=0;i<n;i++){
            if(grid[0][i] && !vis[0][i])
                dfs(grid,0,i);
            if(grid[m-1][i] && !vis[m-1][i])
                dfs(grid,m-1,i);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !vis[i][j])
                    count++;
            }
        }
        return count;
    }
};