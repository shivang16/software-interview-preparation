class Solution {
public:
    int dp[10000] = {-1};
    int n;
    int findCost(vector <int>& cost,int ind){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = cost[ind]+min(findCost(cost,ind+1),findCost(cost,ind+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        for(int i=0;i<10000;i++) dp[i] = -1;
        return min(findCost(cost,0),findCost(cost,1));
    }
};