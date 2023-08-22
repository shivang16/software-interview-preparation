class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        
        vector <int> ans(n,-1);
        
        stack <int> firstGreater;
        stack <int> secondGreater; 
        for(int i=0;i<n;i++){
            int el = nums[i];
            while(!secondGreater.empty() && nums[secondGreater.top()] < nums[i]){
                ans[secondGreater.top()] = nums[i];
                secondGreater.pop();
            }
            stack <int> temp;
            while(!firstGreater.empty() && nums[firstGreater.top()] < nums[i]){
                temp.push(firstGreater.top());
                firstGreater.pop();
            }
            while(!temp.empty()){
                secondGreater.push(temp.top());
                temp.pop();
            }
            firstGreater.push(i);
        }
        return ans;
    }
};