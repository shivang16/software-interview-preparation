// https://leetcode.com/problems/2-keys-keyboard/description
class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        for(int i=0;i<=n;i++)
            dp[i] = INT_MAX;
        dp[0] = 0;
        dp[1] = 0;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if((i-j)%j==0){
                    dp[i] = min(dp[i],dp[j]+(i-j)/j+1);
                }
            }
        }
        return dp[n];
    }
};