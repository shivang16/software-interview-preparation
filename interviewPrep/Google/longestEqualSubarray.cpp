// https://leetcode.com/problems/find-the-longest-equal-subarray/submissions/
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = 0, crntFreq = 0, ans=0;
        unordered_map <int,int> M;
        while(high<n){
            M[nums[high]]++;
            crntFreq = max(crntFreq,M[nums[high]]);
            while((high-low+1)-crntFreq > k){
                M[nums[low]]--;
                low++;
            }
            ans = max(ans,crntFreq);
            high++;
        }
        return ans;
    }
};