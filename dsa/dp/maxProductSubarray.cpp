class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int neg = nums[0];
        int pos = nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = max({nums[i],nums[i]*neg,nums[i]*pos});
            neg = min({nums[i],nums[i]*neg,nums[i]*pos});
            pos = max(temp,neg);
            ans = max(ans,temp);
            
        }
        return ans;
    }
};