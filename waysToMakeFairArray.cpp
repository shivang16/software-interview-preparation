// https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int ans = 0;
        vector<int>oddsum(nums.size()), evensum(nums.size());
        int curroddsum = 0, currevensum = 0;
        for(int i = nums.size()-1; i>=0; i--){
            oddsum[i] = curroddsum;
            evensum[i] = currevensum;
            
            if(i%2==0){
                currevensum+=nums[i];
            }
            else{
                curroddsum+=nums[i];
            }
        }
        
        curroddsum=0, currevensum=0;
        for(int i = 0; i<nums.size(); i++){
            if(curroddsum+evensum[i] == currevensum+oddsum[i]){
                ans++;
            }
            
            if(i%2==0){
                currevensum+=nums[i];
            }
            else{
                curroddsum+=nums[i];
            }
        }
        
        return ans;
    }
};