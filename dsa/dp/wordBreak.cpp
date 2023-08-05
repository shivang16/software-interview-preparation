class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set <string> S;
        for(auto i:wordDict) S.insert(i);
        vector <bool> dp(n+1,false);
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && S.find(s.substr(j,i-j))!=S.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
