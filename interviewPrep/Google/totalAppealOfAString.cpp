// https://leetcode.com/problems/total-appeal-of-a-string/
class Solution {
public:
    long long appealSum(string s) {
        unordered_map <char,int> mp;
        long long ans = 0;
        int n = s.size();
        vector <long long> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1];
            if(mp.count(s[i-1])==0){
                dp[i]+=i;
            }else{
                dp[i]+=(i-mp[s[i-1]]);
            }
            mp[s[i-1]] = i;
            ans+=dp[i];
        }
        return ans;
        
    }
};