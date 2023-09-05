// https://leetcode.com/problems/path-with-minimum-effort/
class Solution {
public:
    int m,n;
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
    
    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }

    typedef pair <int,pair <int,int>> pr;

    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector <vector <int>> dp(m,vector <int> (n,INT_MAX));
        priority_queue <pr,vector <pr>, greater <pr>> pq;
        dp[0][0] = 0;
        pq.push({0,{0,0}});
        while(pq.size()){
            auto [x,y] = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if(x==m-1 && y==n-1) return dp[x][y];

            for(int i=0;i<4;i++){
                int nx = x+X[i], ny = y+Y[i];
                if(isValid(nx,ny)){
                    int diff = abs(heights[x][y]-heights[nx][ny]);
                    int newMax = max(dis,diff);
                    if(newMax < dp[nx][ny]){
                        dp[nx][ny] = newMax;
                        pq.push({newMax,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};