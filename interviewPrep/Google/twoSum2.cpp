// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        int l=0,r=nums.size();
        while(r>l){
            if(nums[l]+nums[r]==target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                
                return ans;
            }else if(nums[l]+nums[r]>target)
                r--;
            else
                l++;
        }
        return ans;
    }
};