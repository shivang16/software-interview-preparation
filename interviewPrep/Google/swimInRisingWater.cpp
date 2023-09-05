// https://leetcode.com/problems/swim-in-rising-water/description/
class Solution {
public:
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
    int n;
    bool isValid(int x,int y){
        return x>=0 && x<n && y>=0 && y<n;
    }

    void dfs(vector<vector<int>>& grid,int x,int y,vector <vector <int>> &vis,int mx,int &ans){
        if(x==n-1 && y==n-1){
            ans = min(ans,mx);
            return;
        }
        if(!(vis[x][y]==-1 || vis[x][y]>mx)) return;
        vis[x][y] = mx;
        for(int i=0;i<4;i++){
            int nx = x+X[i];
            int ny = y+Y[i];
            if(isValid(nx,ny)){
                dfs(grid,nx,ny,vis,max(mx,grid[nx][ny]),ans);
            }   
        }

    }
    typedef pair <int,pair <int,int>> pr;
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        // int mx = grid[0][0];
        // vector <vector <int>> vis(n,vector <int>(n,-1));
        // int ans = INT_MAX;
        // dfs(grid,0,0,vis,mx,ans);
        // return ans;
        vector <vector <bool>> vis(n,vector <bool>(n,false));
        
        priority_queue <pr,vector <pr>, greater <pr>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0] = true;
        while(pq.size()){
            int time = pq.top().first;
            auto [x,y] = pq.top().second;
            pq.pop();
            if(x==n-1 && y==n-1) return time;
            for(int i=0;i<4;i++){
                int nx = x+X[i], ny = y+Y[i];
                if(isValid(nx,ny) && !vis[nx][ny]){
                    int newTime = max(time,grid[nx][ny]);
                    pq.push({newTime,{nx,ny}});
                    vis[nx][ny] = true;
                }
            }
        }
        return INT_MAX;
    }
};