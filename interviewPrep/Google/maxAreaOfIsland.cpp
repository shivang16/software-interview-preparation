// https://leetcode.com/problems/max-area-of-island/description/
class Solution {
public:
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
    int m,n;
    bool isValid(int x>,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    int temp;
    void dfs(vector<vector<int>>& grid,int x,int y,vector <vector <bool>> &vis){
        if(!isValid(x,y)) return;
        if(vis[x][y] || grid[x][y]==0) return;
        vis[x][y] = true;
        temp++;
        for(int i=0;i<4;i++)
            dfs(grid,x+X[i],y+Y[i],vis);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(),n=grid[0].size();
        vector <vector <bool>> vis(m,vector <bool> (n,false));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    temp = 0;
                    dfs(grid,i,j,vis);
                    ans = max(ans,temp);
                    temp = 0;
                }
            }
        }
        return ans;
    }
};