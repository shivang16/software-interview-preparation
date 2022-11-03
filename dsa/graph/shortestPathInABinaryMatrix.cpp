// https://leetcode.com/problems/shortest-path-in-binary-matrix/submissions/

class Solution {
public:
    
    int X[8] = {0,0,1,-1,1,-1,1,-1};
    int Y[8] = {1,-1,0,0,1,1,-1,-1};
    int n;
    int ans = INT_MAX;
    vector <vector <bool>> vis;
    bool isValid(int x,int y){
        return x>=0&&x<n&&y>=0&&y<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        vis = vector <vector <bool>> (n,vector <bool>(n,false));
        if(grid[0][0]==1||grid[n-1][n-1]==1)
            return -1;
        queue <pair <pair<int,int>,int>> Q;
        Q.push({{0,0},1});
        vis[0][0] = true;
        while(!Q.empty()){
            auto frnt = Q.front();
            int x = frnt.first.first,y=frnt.first.second,dis=frnt.second;
            Q.pop();
            if(x==n-1&&y==n-1){
                return dis;
            }
            for(int i=0;i<8;i++){
                int nx = x+X[i],ny = y+Y[i];
                if(isValid(nx,ny) && !vis[nx][ny] && grid[nx][ny]==0){
                    vis[nx][ny] = true;
                    Q.push({{nx,ny},dis+1});
                }
            }

        }
        return -1;
    }
};