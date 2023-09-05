// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/
class Solution {
public:
    int m,n;
    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    vector <vector <int>> dp;
    typedef pair <int,pair <int,int>> pr;
    int minimumTime(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m,vector <int> (n,INT_MAX));

        if(grid[0][1]>grid[0][0]+1 && grid[1][0]>grid[0][0]+1)
            return -1;
        
        dp[0][0] = 0;
        priority_queue <pr,vector <pr>, greater <pr>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto [x,y] = pq.top().second;
            auto time = pq.top().first;
            // cout << x << " " << y << " " << wt << endl;
            pq.pop();
            for(int i=0;i<4;i++){
                int nx = x+X[i], ny = y+Y[i];
                if(isValid(nx,ny)){
                    int finalTime;
                    if(grid[nx][ny]>time+1){
                        int diff = grid[nx][ny]-time;
                        if(diff%2) finalTime = grid[nx][ny];
                        else finalTime = grid[nx][ny]+1;
                    }else{
                        finalTime = time+1;
                    }
                    if(dp[nx][ny] > finalTime){
                        dp[nx][ny] = finalTime;
                        pq.push({finalTime,{nx,ny}});
                    }
                }
            }
        }
        return dp[m-1][n-1]==INT_MAX?-1:dp[m-1][n-1];
    }
};