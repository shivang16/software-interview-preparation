class Solution {
public:
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
    int m,n;
    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }

    bool isBorder(int x,int y){
        return x==0 || y==0 || x==m-1 || y==n-1;
    }
    
    void dfs(vector<vector<int>>& grid,vector <vector <bool>> &vis,int x,int y,int target,int prev){
        vis[x][y] = true;
        if(isBorder(x,y))
            grid[x][y] = target;
        for(int i=0;i<4;i++){
            int nx = x+X[i];
            int ny = y+Y[i];
            bool req = false;
            if(isValid(nx,ny) && !vis[nx][ny]){
                if(grid[nx][ny]!=prev){
                    req = true;
                }else{
                    dfs(grid,vis,nx,ny,target,prev);
                }
            }
            if(req)
                grid[x][y] = target;
        }
    }


    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size(), n = grid[0].size();
        vector <vector <bool>> vis(m,vector <bool> (n,false));
        dfs(grid,vis,row,col,color,grid[row][col]);
        return grid;
    }
};