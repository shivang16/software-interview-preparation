// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
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
    int minCost(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m,vector <int> (n,INT_MAX));
        dp[0][0] = 0;
        //  (wt,(x,y))
        priority_queue <pr,vector <pr>, greater <pr>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto [x,y] = pq.top().second;
            auto wt = pq.top().first;
            pq.pop();

            for(int i=0;i<4;i++){
                int count = grid[x][y]-1 != i;
                int nx = x+X[i], ny = y+Y[i];
                if(isValid(nx,ny)){
                    if(dp[nx][ny] > wt + count){
                        dp[nx][ny] = wt+count;
                        pq.push({wt+count,{nx,ny}});
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};