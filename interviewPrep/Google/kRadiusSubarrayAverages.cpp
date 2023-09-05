// https://leetcode.com/problems/k-radius-subarray-averages/submissions/
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0,high = 0;
        vector <int> ans;
        if(k==0) return nums;
        if(k>=n-1){
            for(int i=0;i<n;i++)
                ans.push_back(-1);
            return ans;
        }
        for(int i=0;i<k;i++)
            ans.push_back(-1);
        long long sum = 0;
        int newK = 2*k+1;
        while(high<n){
            sum+=nums[high];
            if(high-low+1==newK){
                ans.push_back(sum/newK);
                sum-=nums[low];
                low++;
            }
            high++;
        }
        for(int i=0;i<k;i++)
            ans.push_back(-1);
        return ans;
    }
};