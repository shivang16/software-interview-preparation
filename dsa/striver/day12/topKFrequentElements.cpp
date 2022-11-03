// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> ans;
        priority_queue <pair <int,int>> Q;
        unordered_map <int,int> M;
        for(auto i:nums)
            M[i]++;
        for(auto i:M)
            Q.push({i.second,i.first});
        for(int i=0;i<k;i++){
            ans.push_back(Q.top().second);
            Q.pop();
        }
            return ans;
    }
};