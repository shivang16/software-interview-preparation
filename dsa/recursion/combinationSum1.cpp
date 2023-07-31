class Solution {
public:
    set <vector <int>> S;
    void findSum(vector <int> &nums,int i,int target,vector <int> temp){
        if(target==0){
            S.insert(temp);
            return;
        }
        if(i<0|| target<0) return;
        findSum(nums,i-1,target,temp);
        temp.push_back(nums[i]);
        findSum(nums,i,target-nums[i],temp);
        temp.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector <int> temp;
        findSum(candidates,candidates.size()-1,target,temp);
        vector <vector <int>> ans;
        for(auto i:S) ans.push_back(i);
        return ans;
    }
};