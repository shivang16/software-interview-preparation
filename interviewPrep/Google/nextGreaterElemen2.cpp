class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n,-1);
        stack <int> S;
        for(int i=0;i<2*n;i++){
            while(!S.empty() && nums[S.top()%n] < nums[i%n]){
                ans[S.top()%n] = nums[i%n];
                S.pop();
            }
            S.push(i);
        }
        return ans;
    }
};