class Solution {
public:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    int m,n;
    void dfs(vector<vector<char>>& grid,int x,int y,vector <vector <bool>> &vis){
        if(x<0||x>=m||y<0||y>=n)
            return;
        if(vis[x][y])
            return;
        vis[x][y] = true;
        if(grid[x][y]=='1'){
            for(int i=0;i<4;i++)
                dfs(grid,x+X[i],y+Y[i],vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(),n=grid[0].size();
        vector <vector <bool>> vis(m,vector <bool>(n,false));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid,i,j,vis);
                    ans++;
                }
                    
            }
        }
        return ans;
    }
};