class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector <int> dp(110);
        dp[0] = 1;
        dp[1] = s[0]=='0'?0:1;
        for(int i=2;i<=n;i++){
            int d = s[i-1]-'0';
            int dd = s[i-2]-'0';
            int num = dd*10+d;
            if(d>=1) dp[i]+=dp[i-1];
            if(num>=10&&num<=26) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};