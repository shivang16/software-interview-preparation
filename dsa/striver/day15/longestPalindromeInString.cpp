class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0)
            return s;
        bool dp[n][n];
        memset(dp,true,sizeof(dp));
        int mx = 1;
        int b=0,e=0;
        for(int gap=1;gap<n;gap++)
        {
            for(int i=0;i<n-gap;i++)
            {
                int j = i+gap;
                if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = false;
                if(dp[i][j])
                {
                    b = i;
                    e = j;
                    
                }
            }
        }
        string ans = s.substr(b,e-b+1);
        return ans;
        
    }
};