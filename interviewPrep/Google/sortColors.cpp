class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = -1, m = 0, r = n;
        while(m>l && m<r){
            if(nums[m]==0){
                l++;
                swap(nums[l],nums[m]);
                m++;
            }else if(nums[m]==2){
                r--;
                swap(nums[r],nums[m]);
            }else
                m++;
        }
    }
};

