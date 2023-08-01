class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> Q;
        for(auto i:nums){
            Q.push(i);
        }
        while(--k){
            Q.pop();
        }
        return Q.top();
    }
};