class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue <pair <int,int>> Q;
        int l=-1,h=0,n=nums.size();
        vector <int> ans;
        while(h<n){
            Q.push({nums[h],h});
            if(h-l==k){
                while(Q.top().second<=l) Q.pop();
                ans.push_back(Q.top().first);
                l++;
            }
            h++;
            
        }
        return ans;
    }
};