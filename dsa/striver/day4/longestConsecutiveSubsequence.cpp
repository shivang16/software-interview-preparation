// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return n;
        unordered_map <int,int> M;
        unordered_map <int,bool> vis;
        unordered_map <int,int> dp;
        int ans = 0;
        for(int i=0;i<n;i++){
            M[nums[i]] = i;
            vis[nums[i]] = false;
            dp[nums[i]] = 1;
        }
        for(int i=0;i<nums.size();i++){
            int crnt = nums[i];
            if(!vis[crnt]){
                int count = 0;
                while(M.find(crnt)!=M.end()){
                    if(vis[crnt]){
                        count+=dp[crnt];
                        break;
                    }else{
                        vis[crnt] = true;
                        count++;
                        crnt++;   
                    }
                }
                dp[nums[i]] = count;
            }
        }
        for(int i=0;i<n;i++)
            ans = max(ans,dp[nums[i]]);
        return ans;
        
    }
};