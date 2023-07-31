class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int found = 0;
        int ind = 0;
        while(ind<n){
            if(nums[ind]==nums[found])
                ind++;
            else{
                found++;
                nums[found] = nums[ind];
            }
        }
        return found+1;
    }
};