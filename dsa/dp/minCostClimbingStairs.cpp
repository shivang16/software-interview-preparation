class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> C(n+1,0);
        C[1] = 0;
        C[2] = 0;
        for(int i=2;i<=n;i++)
            C[i] += min(C[i-1]+cost[i-1],C[i-2]+cost[i-2]);
        return C[n];
    }
};