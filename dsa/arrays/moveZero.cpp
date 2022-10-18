class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zc = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                zc++;
            else
                swap(nums[i],nums[i-zc]);
        }

    }
};
