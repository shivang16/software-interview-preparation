class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(r>l){
            int mid = (l+r)/2;
            if(nums[mid]<nums[r]){
                r = mid;
            }else if(nums[mid]>nums[r]){
                l = mid+1;
            }else{
                r--;
            }
        }
        return nums[l];
    }
};