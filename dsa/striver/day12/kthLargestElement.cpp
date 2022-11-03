// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> Q;
        for(auto i:nums)
            Q.push(i);
        for(int i=0;i<k-1;i++)
            Q.pop();
        return Q.top();
    }
};