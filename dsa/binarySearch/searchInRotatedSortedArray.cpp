class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(r>=l){
            int m = (l+r)/2;
            if(nums[m]==target){
                return m;
            }

            if(nums[m]>=nums[l]){
                if(nums[l]<=target && nums[m]>=target)
                    r = m-1;
                else
                    l = m+1;
            }else{
                if(nums[m]<=target && nums[r]>=target)
                    l = m+1;
                else
                    r = m-1;
            }
        }int ans = -1;
        
        return -1;
    }
};