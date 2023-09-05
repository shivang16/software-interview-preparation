// https://leetcode.com/problems/reducing-dishes/
class Solution {
public:
    int getAns(vector <int>& sat,int ind,int time,vector <vector  <int>> &dp){
        if(ind==sat.size()) return 0;
        if(time>ind) return 0;
        if(dp[ind][time]!=-1) return dp[ind][time];
        return dp[ind][time] = max(getAns(sat,ind+1,time,dp),sat[ind]*(time+1)+getAns(sat,ind+1,time+1,dp));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector <vector <int>> dp(n+1,vector <int> (n+1,-1));
        return getAns(satisfaction,0,0,dp);
    }
};