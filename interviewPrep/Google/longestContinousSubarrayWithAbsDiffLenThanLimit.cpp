
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/submissions/
class Solution {
public:
    
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue <pair <int,int>> mxQ;
        priority_queue <pair <int,int>, vector <pair <int,int>>, greater<pair<int,int>>> mnQ;
        int ans = 0;
        int l=0,r=0;
        while(r<n){
            mxQ.push({nums[r],r});
            mnQ.push({nums[r],r});
            while(mxQ.top().second<l)
                mxQ.pop();
            while(mnQ.top().second<l)
                mnQ.pop();
            if(mxQ.top().first-mnQ.top().first<=limit){
                ans = max(ans,r-l+1);
                r++;
            }else{
                l++;
                r++;
            }    
        }
        return ans;
    }
};