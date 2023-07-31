class Solution {
public:
    void findPermute(vector <int>& nums,int ind,vector <vector <int>> &ans){
        if(ind==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            findPermute(nums,ind+1,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        findPermute(nums,0,ans);
        return ans;
    }
};