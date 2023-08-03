class KthLargest {
public:
    priority_queue <int,vector <int>,greater <int>> Q;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto i:nums)
            add(i);
    }
    
    int add(int val) {
        Q.push(val);
        if(Q.size()>K)
            Q.pop();
        return Q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */