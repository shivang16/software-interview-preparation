// https://leetcode.com/problems/number-of-longest-increasing-subsequence
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n,1);
        vector <int> dp1(n,1);
        int mx = 1;
        dp[0] = 1;
        dp1[0] = 1; 
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                        dp1[i] = dp1[j];
                        dp[i] = dp[j]+1;
                    }else if(dp[i]==dp[j]+1){
                        dp1[i]+=dp1[j];
                    }
                }
            }
            mx = max(mx,dp[i]);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx){
                count+=dp1[i];
            }
            // cout << i << " " << dp[i] << " " << dp1[i] << endl;
        }
        return count;
    }
};