class Solution {
public:
    int findAns(vector <int>& nums,int target,int ind,int sum,map <pair<int,int>,int> &dp){
        if(ind<0){
            if(sum==target)
                return 1;
            return 0;
        }
        if(dp.find({ind,sum})!=dp.end()) return dp[{ind,sum}];
        return dp[{ind,sum}] = findAns(nums,target,ind-1,sum+nums[ind],dp)+findAns(nums,target,ind-1,sum-nums[ind],dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        map <pair<int,int>,int> dp;
        return findAns(nums,target,nums.size()-1,ans,dp);
    }
};