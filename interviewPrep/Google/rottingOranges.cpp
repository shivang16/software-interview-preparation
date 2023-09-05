// https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
    int m,n;
    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        queue <pair <pair <int,int>,int>> Q;

        vector <vector <bool>> vis(m,vector <bool> (n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j] = true;
                    Q.push({{i,j},0});
                }
            }
        }
        int ans=0;
        while(!Q.empty()){
            int x = Q.front().first.first;
            int y = Q.front().first.second;
            int time = Q.front().second;
            ans = max(ans,time);
            Q.pop();
            for(int i=0;i<4;i++){
                int nx = x+X[i];
                int ny = y+Y[i];
                if(isValid(nx,ny) && !vis[nx][ny] && grid[nx][ny]==1){
                    vis[nx][ny] = true;
                    Q.push({{nx,ny},time+1});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    return -1;
            }
        }
        return ans;
    }
};