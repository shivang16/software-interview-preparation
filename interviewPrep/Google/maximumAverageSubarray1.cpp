// https://leetcode.com/problems/maximum-average-subarray-i/submissions/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n  = nums.size();
        double ans = INT_MIN;
        int sum = 0;
        int low = 0, high = 0;
        while(high<n){
            sum+=nums[high];
            if(high-low+1==k){
                double avg = (double)sum/k;
                ans = max(ans,avg);
                sum-=nums[low];
                low++;
            }
            high++;
        }
        return ans;
    }
};