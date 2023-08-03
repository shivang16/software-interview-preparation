class Solution {
public:
    bool findSum(vector <int> &nums,int sum, int i){
        if(sum<0) return false;
        if(i==0){
            return nums[0]==sum;
        }
        return findSum(nums,sum,i-1)||findSum(nums,sum-nums[i],i-1);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto i:nums) totalSum+=i;
        if(totalSum%2) return false;
        int reqSum = totalSum/2;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector <vector <bool>> dp(n+1,vector <bool> (reqSum+1,false));
        for(int i=0;i<=n;i++) dp[i][0] = true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=reqSum;j++){
                if(j==nums[i-1]){
                    dp[i][j] = true;
                }else if(j>nums[i-1]){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][reqSum];
    }
};