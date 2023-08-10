// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
class Solution {
public:
    int m,n;
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,-1,1};

    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    
    // int dfs(vector <vector <int>>& grid,int x,int y,vector <vector <bool>>& vis,int k,int pathLength,int &ans){
    //     if(!isValid(x,y)) return 100000;
    //     if(x==m-1 && y==n-1){
    //         ans = min(ans,pathLength);
    //         return 0;
    //     } 
    //     if(vis[x][y]) return 100000;
    //     if(grid[x][y]==1 && k<=0)
    //         return 100000;
    //     vis[x][y] = true;
    //     int temp = 100000;
    //     for(int i=0;i<4;i++){
    //         temp = min(temp,grid[x][y]+dfs(grid,x+X[i],y+Y[i],vis,k-grid[x][y],pathLength+1,ans));
    //     }
    //     vis[x][y] = false;
    //     return temp;
    // }
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        vector <vector <int>> vis(m,vector <int> (n,-1));
        queue <vector <int>> Q;
        Q.push({0,0,k,0});
        while(!Q.empty()){
            auto front = Q.front();
            int x = front[0];
            int y = front[1];
            int kRem = front[2];
            int dis = front[3];
            int sz = Q.size();
            Q.pop();

            if(!isValid(x,y)) continue;
            if(x==m-1 && y==n-1) return dis;

            if(grid[x][y]==1){
                if(kRem<=0)
                    continue;
                kRem--;
            }
            if(vis[x][y]!=-1 && vis[x][y]>=kRem)
                continue;
            
            vis[x][y] = kRem;
            for(int i=0;i<4;i++)
                Q.push({x+X[i],y+Y[i],kRem,dis+1});
        }
        return -1;  
    }
};