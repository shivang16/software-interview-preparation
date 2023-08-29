class Solution {
public:
    unordered_map<string, int> dp;
    bool util(string s, string p, int n, int m){
        string key = to_string(n) + to_string(m);

        if(n <= -1 && m <= -1)
            return true;

        if(n == -1 && p[m] == '*')
            return util(s, p, n, m-2);

        if(n == -1 || m == -1)
            return false;

        if(dp.count(key))
            return dp[key];

        if(s[n] == p[m]){
            dp[key] = util(s, p, n-1, m-1);
        }
        else{
            if(p[m] == '*'){
                if(s[n] == p[m-1] || p[m-1] == '.'){
                    dp[key] = (util(s, p, n-1, m) || util(s, p, n, m-2));
                }
                else{
                    dp[key] = util(s, p, n, m-2);
                }
            }
            else if(p[m] == '.'){
                dp[key] = util(s, p, n-1, m-1);
            }
            else
                dp[key] = false;
        }

        return dp[key];
    }

    bool isMatch(string s, string p) {
        return util(s, p, s.length()-1, p.length()-1);
    }
};