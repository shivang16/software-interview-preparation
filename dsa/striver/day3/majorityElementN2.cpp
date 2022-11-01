// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        int ind = 0,count=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[ind])
                count++;
            else{
                if(count==1){
                    ind = i;
                    count=1;
                }else{
                    count--;
                }
            }
        }
        return nums[ind];
    }
};