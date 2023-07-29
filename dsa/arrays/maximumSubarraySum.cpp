// https://leetcode.com/problems/maximum-subarray/description/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sumTillNow = 0;
        int ans=0;
        bool allNegative = true;
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                allNegative = false;
            }
            mx = max(mx,nums[i]);
            sumTillNow+=nums[i];
            ans = max(ans,sumTillNow);
            if(sumTillNow<0){
                sumTillNow=0;
            }
        }
        return allNegative?mx:ans;
    }
};