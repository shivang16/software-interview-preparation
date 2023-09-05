// https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/solutions/3867909/c-easy-solution-using-map-best-approach/
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,vector <int>> Mp;
        for(int i=0;i<n;i++){
            Mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto [val,pos]: Mp){
            pos.push_back(pos[0]+n);
            int time = INT_MIN;
            for(int i=0;i<pos.size()-1;i++){
                time = max(time,(pos[i+1]-pos[i])/2);
            }
            ans = min(ans,time);
        }
        return ans;
    }
};