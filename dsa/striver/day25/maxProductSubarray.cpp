https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int neg = nums[0];
        int pos = nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = max({nums[i],pos*nums[i],neg*nums[i]});
            neg = min({nums[i],pos*nums[i],neg*nums[i]});
            pos = max(temp,neg);
            ans = max(ans,pos);
        }
        return ans;
    }
};
