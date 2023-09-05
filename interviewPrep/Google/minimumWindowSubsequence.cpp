// https://www.lintcode.com/problem/857/
class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: the minimum substring of S
     */
     bool isSubseq(string &s,string &t){
         if(t.size()> s.size()) return false;
         if(t.size()==s.size() && t!=s) return false;
         if(t==s) return true;
         int i = 0, j = 0;
         while(i<s.size() && j<t.size()){
             if(s[i]==t[j]){
                 i++;
                 j++;
             }else{
                 i++;
             }
         }
         return j==t.size();
     }
    string minWindow(string &s, string &t) {
        string ans = "", temp = "";
        int l = 0, r = 0;
        while(r<s.size()){
            temp+=s[r];
            while(temp.size() && isSubseq(temp,t)){
                if(ans=="")
                    ans = temp;
                if(ans!="" && ans.size() > temp.size()){
                    ans = temp;
                }
                if(ans.size()==t.size()) return ans;
                temp = temp.substr(1);
            }
            r++;
        }
        return ans;
    //     // Write your code here
    //     onst int m = s2.length();
    // const int n = s1.length();
    // // dp[i][j] := start index (1-indexed) of the min window of s2[0..i] and
    // // s1[0..j).
    // vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // // Fill in placeholder values
    // for (int j = 0; j <= n; ++j)
    //   dp[0][j] = j + 1;

    // for (int i = 1; i <= m; ++i)
    //   for (int j = 1; j <= n; ++j)
    //     if (s2[i - 1] == s1[j - 1])
    //       dp[i][j] = dp[i - 1][j - 1];
    //     else
    //       dp[i][j] = dp[i][j - 1];

    // int bestLeft = 0;
    // int minLength = INT_MAX;

    // for (int j = 1; j <= n; ++j)
    //   if (dp[m][j] > 0 && j - dp[m][j] + 1 < minLength) {
    //     bestLeft = dp[m][j] - 1;
    //     minLength = j - dp[m][j] + 1;
    //   }

    // return minLength == INT_MAX ? "" : s1.substr(bestLeft, minLength);
    }
};