class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector <vector <int>> ans;
        set <pair<int,pair<int,int>>> S;
        for(int i=0;i<nums.size()-2;i++){
            int targetSum = -nums[i];
            int l=i+1,h=nums.size()-1;
            while(h>l){
                if(targetSum>nums[l]+nums[h]){
                    l++;
                }else if(targetSum<nums[l]+nums[h]){
                    h--;
                }else{
                    S.insert({nums[i],{nums[l],nums[h]}});
                    h--;
                }
            }
        }
        for(auto i:S){
            vector <int> v;
            v.push_back(i.first);
            v.push_back(i.second.first);
            v.push_back(i.second.second);
            ans.push_back(v);
        }
        return ans;
    }
};