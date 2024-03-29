// https://leetcode.com/problems/maximum-length-of-pair-chain/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector <int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i],1+dp[j]);
            }
        }
        return dp[n-1];
    }
};