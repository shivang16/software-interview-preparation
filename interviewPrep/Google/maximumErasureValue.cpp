class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, sum = 0;
        unordered_map <int,int> M;
        int low = 0, high = 0;
        while(high<n){
            M[nums[high]]++;
            sum+=nums[high];
            while(M[nums[high]]>1){
                M[nums[low]]--;
                sum-=nums[low];
                low++;
            }
            ans = max(ans,sum);
            high++;
        }
        return ans;
    }
};