// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9+7;
        int dp[n+1][target+1];

        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++)
                dp[i][j] = 0;
        }
        for(int i=1;i<=min(k,target);i++)
            dp[1][i] = 1;

        for(int i=2;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int m=1;m<=k;m++){
                    if(j-m>=0){
                        dp[i][j] = (dp[i][j]+dp[i-1][j-m])%mod; 
                    }
                }
            }
        }
        return dp[n][target];
        
    }
};