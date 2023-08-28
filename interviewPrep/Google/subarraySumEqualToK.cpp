class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> M;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            M[sum]++;
            sum+=nums[i];
            ans+=M[sum-k];
        }
        return ans;
    }
};