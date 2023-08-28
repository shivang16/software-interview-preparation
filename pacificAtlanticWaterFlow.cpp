class Solution {
public:
    int m,n;
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,-1,1};
    vector <vector <bool>> pacific;
    vector <vector <bool>> atlantic;
    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    void dfs(vector <vector <int>>& height,vector <vector <bool>>& ocean, int x,int y){
        ocean[x][y] = true;
        for(int i=0;i<4;i++){
            int nx = x+X[i];
            int ny = y+Y[i];
            if(isValid(nx,ny) && height[nx][ny]>=height[x][y] && !ocean[nx][ny])
                dfs(height,ocean,nx,ny);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        pacific.resize(m,vector <bool> (n,false));
        atlantic.resize(m,vector <bool> (n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)
                    dfs(heights,pacific,i,j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1 || j==n-1)
                    dfs(heights,atlantic,i,j);
            }
        }
        vector <vector <int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    vector <int> temp = {i,j};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
        
    }
};