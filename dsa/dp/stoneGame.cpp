// https://leetcode.com/problems/stone-game/


class Solution {
public:
    int ans(vector<int>& piles, int b,int e,vector <vector <int>> &dp){
        if(b>=e) return 0;
        if(dp[b][e]!=-1) return dp[b][e];
        int x = piles[b]-ans(piles,b+1,e,dp);
        int y = piles[e]-ans(piles,b,e-1,dp);
        return dp[b][e] = max(x,y);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector <vector <int>> dp(n,vector <int> (n,-1));
        return ans(piles,0,piles.size()-1,dp)>0;
    }
};