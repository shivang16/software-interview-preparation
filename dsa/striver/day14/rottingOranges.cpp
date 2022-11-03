//https://leetcode.com/problems/rotting-oranges
class Solution {
public:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    int m,n;
    bool isValid(int x,int y){
        return x>=0&&x<m&&y>=0&&y<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(),n=grid[0].size();
        vector <vector <bool>> vis(m,vector <bool>(n,false));
        queue <pair <int,pair<int,int>>> Q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                        Q.push({0,{i,j}});
                    vis[i][j] = true;
                    
                }
            }
        }
        int ans = 0;
        while(!Q.empty()){
            int x = Q.front().second.first,y=Q.front().second.second;
            int dis = Q.front().first;
            Q.pop();
            ans = max(ans,dis);
            for(int i=0;i<4;i++){
                int nx = x+X[i],ny = y+Y[i];
                if(isValid(nx,ny)&&!vis[nx][ny]&&grid[nx][ny]==1){
                    Q.push({dis+1,{nx,ny}});
                    vis[nx][ny] = true;
                    grid[nx][ny] = 2;
                }
                    
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                    return -1;
        return ans;
    }
};
