// https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        int l = 0,n = nums.size();
        while(l<n){
            if(nums[l]==1){
                int r = l+1;
                while(r<n && nums[r]==1)
                    r++;
                ans = max(ans,r-l);
                l=r;
            }else
                l++;
        }
        return ans;
    }
};