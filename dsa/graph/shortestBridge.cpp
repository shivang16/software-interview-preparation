// https://leetcode.com/problems/shortest-bridge/
class Solution {
public:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    int n;
    bool isValid(int x,int y){
        return x>=0&&x<n&&y>=0&&y<n;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector <vector <bool>> vis(n,vector <bool>(n,false));
        queue <pair <int,pair<int,int>>> Q;
        int nx=-1,ny=-1;
        bool found = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    nx = i;ny=j;
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
        Q.push({0,{nx,ny}});
        vis[nx][ny] = true;
        while(!Q.empty()){
            int x = Q.front().second.first,y=Q.front().second.second;
            Q.pop();
            for(int i=0;i<4;i++){
                nx = X[i]+x;ny=Y[i]+y;
                if(isValid(nx,ny)&&!vis[nx][ny]&&grid[nx][ny]==1){
                    Q.push({0,{nx,ny}});
                    vis[nx][ny] = true;
                }
                    
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j])
                    Q.push({0,{i,j}});
            }
        }
        int ans = 0;
        while(!Q.empty()){
            int x = Q.front().second.first,y=Q.front().second.second;
            int dis = Q.front().first;
            Q.pop();
            for(int i=0;i<4;i++){
                nx = X[i]+x;ny=Y[i]+y;
                if(isValid(nx,ny)&&!vis[nx][ny]){
                    if(grid[nx][ny]==1)
                        return dis;
                    else{
                        Q.push({dis+1,{nx,ny}});
                        vis[nx][ny] = true;
                    }
                               
                }
            }
        }
        return 0;
    }
};