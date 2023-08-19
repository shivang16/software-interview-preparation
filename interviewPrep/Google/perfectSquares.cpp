class Solution {
public:
    int numSquares(int n) {
        set <int> sq;
        int dp[10001];
        for(int i=0;i<=n;i++) dp[i] = INT_MAX;
        // cout << dp[2] << endl;
        dp[0] = 0;
        dp[1] = 1;
        for(int i=1;i<=100;i++){
            sq.insert(i*i);
            dp[i*i] = 1;
        }
        
        for(int i=2;i<=n;i++){
            for(auto j:sq){
                if(i-j>0){

                    // cout << i << " " << j << endl;
                    dp[i] = min(dp[i],dp[j]+dp[i-j]);
                }else{
                    break;
                }
            }
            // cout << "dp: "<<i << " " << dp[i] << endl;
        }
        return dp[n];
    }
};