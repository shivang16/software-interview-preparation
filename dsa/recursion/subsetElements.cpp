class Solution {
public: 
    set <vector <int>> S;  
    void findSubset(vector <int>& nums,int i,vector <int> &temp){
        if(i<0){
            S.insert(temp);
            return;
        }
        findSubset(nums,i-1,temp);
        temp.push_back(nums[i]);
        findSubset(nums,i-1,temp);
        temp.pop_back();
    }  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector <int> x;
        findSubset(nums,nums.size()-1,x);
        vector<vector<int>> ans;
        for(auto i:S){
            ans.push_back(i);
        }
        return ans;
    }
};