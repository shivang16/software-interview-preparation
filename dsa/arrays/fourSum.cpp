class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector <int>> ans;
        int n = nums.size();
        if(n<4) return ans;
        sort(nums.begin(),nums.end());
        set <vector <int>> S;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long newTarget = (long long)target-nums[i]-nums[j];
                int l = j+1, r=n-1;
                bool found = false;
                while(r>l){
                    int sum = nums[r]+nums[l];
                    if(sum==newTarget){
                        S.insert({nums[i],nums[j],nums[l],nums[r]});
                        r--;
                    }else if(sum>newTarget){
                        r--;
                    }else
                        l++;
                }
            }
        }
        for(auto i:S)
            ans.push_back(i);
        return ans;
    }
};