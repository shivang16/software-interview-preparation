// https://leetcode.com/problems/arithmetic-slices/description/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i=0; i<n-2; i++){
            if(nums[i+1] - nums[i] != nums[i+2] - nums[i+1]) continue;
            int flag = 0;
            for(int j=i; j<n-1; j++){
                if(nums[j+1] - nums[j] != nums[i+1] - nums[i]){
                    ans += (j-i-1);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) ans += (n-i-2);
        }
        return ans;
    }
};