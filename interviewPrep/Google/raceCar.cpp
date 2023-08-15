// https://leetcode.com/problems/race-car/submissions/
class Solution {
public:

    int racecar(int t) {
        static vector <int> dp(10000+1,-1);
        if(dp[t]>=0) return dp[t];
        int n = floor(log2(t))+1;
        if(pow(2,n)-1==t)
            dp[t] = n;
        else{
            dp[t] = n+1+racecar(pow(2,n)-1-t);
            for(int i=0;i<=n-2;i++){
                dp[t] = min(dp[t],n+i+1+racecar(t-pow(2,n-1)+pow(2,i)));
            }
        }
        
        return dp[t];
    }
};