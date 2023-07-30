class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mj = nums[0], cnt = 1;
        for(int i=1;i<n;i++){
            if(nums[i]==mj){
                cnt++;
            }else{
                if(cnt==1){
                    mj = nums[i];
                    cnt =1;
                }else{
                    cnt--;
                }
            }
        }
        return mj;
    }
};