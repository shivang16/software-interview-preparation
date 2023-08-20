class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size(), low = 0, high = 0, ans = 0;
        unordered_map <int,int> mp;
        while(high<n){
            mp[nums[high]]++;
            while(mp.size()>k){
                mp[nums[low]]--;
                if(mp[nums[low]]==0) mp.erase(nums[low]);
                low++;
            }
            ans+=(high-low+1);
            high++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return atMostK(nums,k)  - atMostK(nums,k-1);
    }
};