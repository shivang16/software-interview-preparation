// https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& c, int am) {
        int n = c.size();
        if(n==0)
        {
            if(am==0)
                return 0;
            return -1;
        }
        sort(c.begin(),c.end());
        int dp[am+1];
        for(int i=0;i<=am;i++)
            dp[i] = INT_MAX;
        //memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        for(int i=c[0];i<=am;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=c[j] && dp[i-c[j]]!=INT_MAX)
                    dp[i] = min(dp[i],1+dp[i-c[j]]);
            }
        }
        return dp[am]==INT_MAX?-1:dp[am];
        
        
        
    }
};