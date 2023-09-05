// https://leetcode.com/problems/max-consecutive-ones-iii/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zs = 0;
        int n = nums.size(), l=0,r=0,ans=0;
        while(r<n){
            if(nums[r]==0)
                zs++;
            while(zs>k){
                if(nums[l]==0)
                    zs--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};