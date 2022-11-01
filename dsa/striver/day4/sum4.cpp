//https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector <int>> ans;
        int n = nums.size();
        if(n<4)
            return ans;
        sort(nums.begin(),nums.end());
        set <vector <int>> S;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long target1 = (long long)target-nums[i]-nums[j];
                int l = j+1;
                int r = n-1;
                while(r>l){
                    long long x = nums[l]+nums[r];
                    if(x<target1){
                        l++;
                    }else if(x>target1){
                        r--;
                    }else{
                        vector <int> v = {nums[i],nums[j],nums[l],nums[r]};
                        S.insert(v);
                        l++;
                    }
                }
            }
        }
        for(auto i:S)
            ans.push_back(i);
        return ans;
    }
};