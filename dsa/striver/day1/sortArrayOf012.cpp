class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1)
            return;
        int n = nums.size();
        int j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j++;
                swap(nums[i],nums[j]);
            }
        }
        j=0;
        while(j<n && nums[j]==0)
            j++;
        j--;
        for(int i=j+1;i<n;i++){
            if(nums[i]==1){
                j++;
                swap(nums[i],nums[j]);
            }
        }
        
    }
};