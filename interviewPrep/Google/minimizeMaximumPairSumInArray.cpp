class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = INT_MIN;
        int sum = 0;
        int l = 0, r= nums.size()-1;
        while(r>l){
            sum = nums[l]+nums[r];
            ans = max(sum,ans);
            l++;
            r--;
        }
        return ans;
    }
};