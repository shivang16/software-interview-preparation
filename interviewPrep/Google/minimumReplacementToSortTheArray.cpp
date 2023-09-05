// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int prev = INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>prev){
                int x = nums[i]%prev;
                long long y = nums[i]/prev;
                ans+=(y);
                if(x==0){
                    ans--;
                }else{
                    prev = (nums[i])/(y+1);
                }
                // prev = x==0?prev:x;
            }else{
                prev = nums[i];
            }
        }
        return ans;
    }
};