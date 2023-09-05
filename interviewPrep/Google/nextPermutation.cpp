// https://leetcode.com/problems/next-permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind;
        for(ind=n-1;ind>0;ind--){
            if(nums[ind]>nums[ind-1]){
                break;   
            }
        }
        if(ind!=0){
            int ind2 = ind;
            int val = nums[ind-1];
            // Find smallest element > val in right and swap it
            for(int i=ind;i<n;i++){
                if(nums[i]>val && nums[ind2]>nums[i])
                    ind2 = i;
            }
            swap(nums[ind-1],nums[ind2]);
        }   
        sort(nums.begin()+ind,nums.end());
        
    }
};