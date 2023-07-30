class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set <int> S;
        for(auto i:nums){
            S.insert(i);
        }
        int ans = 1;
        for(auto i:nums){
            if(S.find(i-1)!=S.end()){
                continue;
            }else{
                int count = 1;
                int x = i;
                while(S.find(x+1)!=S.end()){
                    count++;
                    x++;
                }
                ans = max(count,ans);
            }
        }
        return ans;
    }
};