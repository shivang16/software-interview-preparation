class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> M;
        priority_queue <pair <int,int>> Q;
        vector <int> ans;
        for(auto i:nums) M[i]++;
        for(auto i:M) Q.push({i.second,i.first});
        while(k--) {
            ans.push_back(Q.top().second);
            Q.pop();
        }
        return ans;
    }
};