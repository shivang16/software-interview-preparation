class Solution {
private: 
    unordered_map <int,vector <int>> Mp;
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            Mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int sz = Mp[target].size();
        int ind = rand()%sz;
        return Mp[target][ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */