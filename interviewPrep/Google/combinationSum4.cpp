// https://leetcode.com/problems/combination-sum-iv/description/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int dp[target+1];
        for(int j=0;j<=target;j++)
            dp[j] = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<=target)
                dp[nums[i]] = 1;
        }
        for(int i=1;i<=target;i++){
            long long temp=dp[i];
            for(int j=0;j<n;j++){
                if(i-nums[j]>=0){
                    temp+=dp[i-nums[j]];
                    // cout << i << " " << j << " " << dp[i] << " " << dp[i-j] <<endl;
                }
            }
            dp[i]=temp;
            // cout<<endl;
        }
        return dp[target];
    }
};