// https://www.lintcode.com/problem/3666/
class Solution {
public:
    /**
     * @param workers: Location of workers
     * @param bikes: Location of bikes
     * @return: Minimum sum of Manhattan distances
     */
    int n,m;
    int dp[11][1<<11];
    int calculateCost(vector <int> &p1,vector <int> &p2){
        return abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
    }
    int helper(vector <vector <int>> &cost,int ind,int mask){
        if(ind==n) return 0;

        if(dp[ind][mask]!=-1) return dp[ind][mask];

        int mini = INT_MAX;
        for(int i=0;i<m;i++){
            if(mask & (1<<i)){
                mini = min(mini,cost[ind][i]+helper(cost,ind+1,mask^(1<<i)));
            }
        }
        return dp[ind][mask] = mini;
    }
    int assignBikesII(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
        // write your code here
        n = workers.size(), m = bikes.size();
        vector <vector <int>> cost(n,vector <int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cost[i][j] = calculateCost(workers[i],bikes[j]);
            }
        }

        for(int i=0;i<11;i++)
            for(int j=0;j<(1<<11);j++)
                dp[i][j] = -1;
        // vector <vector <int>> dp(n,vector <int> (m<<1,-1));
        return helper(cost,0,(1<<m)-1);
    }
};