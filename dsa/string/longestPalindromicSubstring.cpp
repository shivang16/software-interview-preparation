class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int l=0,r=0;
        bool dp[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j] = true;

        for(int dif=0;dif<n;dif++){
            for(int i=0;i<n-dif;i++){
                int j = i+dif;
                if(i==j) dp[i][j] = true;
                else{
                    if(s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }

                // cout << i << " " << j << " " << dp[i][j] << endl;
                if(dp[i][j]){
                    l = i; r = j;
                }
            }
        }
        // cout << l << " " << r;
        return s.substr(l,r-l+1);
    }
    
};