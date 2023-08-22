class Solution {
public:
    void solve(int index, vector<int> &ds,int n, int k,vector<int> &nums,vector<vector<int>> &ans){
        if(k==0){
            if(n==0){
                ans.push_back(ds);
                return;
            }
            return;
        }
    for(int i=index;i<9;i++){
    if(nums[i]>n) break;
        ds.push_back(nums[i]);
        solve(i+1,ds,n-nums[i],k-1,nums,ans);
        ds.pop_back();
    }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int index = 0;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> ds;
        solve(index,ds,n,k,nums,ans);
        return ans;
    }
};