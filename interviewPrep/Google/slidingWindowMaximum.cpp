class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue <pair <int,int>> Q;
        vector <int> ans;
        int n = nums.size();
        int low = 0,high=0;
        while(high<n){
            Q.push({nums[high],high});
            if(high-low+1==k){
                while(Q.top().second<low) Q.pop();
                ans.push_back(Q.top().first);
                low++;
            }
            high++;
        }
        return ans;
    }
};