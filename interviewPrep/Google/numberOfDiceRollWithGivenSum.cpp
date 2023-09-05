// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/submissions/
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int dp[n+1][target+1];
        memset(dp,0,sizeof(dp));
        int mod = 1e9+7;
        for(int i=1;i<=min(target,k);i++)
            dp[1][i] = 1;

        for(int diceCount=2;diceCount<=n;diceCount++){
            for(int sum=1;sum<=target;sum++){
                for(int faceValue=1;faceValue<=k;faceValue++){
                    if(sum>=faceValue){
                        dp[diceCount][sum] = (dp[diceCount][sum]+dp[diceCount-1][sum-faceValue])%mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};