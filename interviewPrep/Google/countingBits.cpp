// https://leetcode.com/problems/counting-bits/description/
class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> dp(n+1,0);
        dp[0] = 0;
        if(n==0) return dp;
        dp[1] = 1;
        if(n==1) return dp;
        dp[2] = 1;
        if(n==2) return dp;
        int p = 1;
        for(int i=3;i<=n;i++){
            int val = pow(2,p);
            int val2 = pow(2,p+1);
            if(val2==i){
                dp[i] = 1;
                p++;
            }else{
                dp[i] = 1+dp[i-val];
            }
        }
        return dp;
    }
};