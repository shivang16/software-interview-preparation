// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map <int,int> mp;
        for(int i=0;i<arr.size();i++){
            int toFind = arr[i]-difference;

            if(mp.find(toFind)!=mp.end()){
                mp[arr[i]] = max(mp[arr[i]],mp[toFind]+1);
            }

            if(mp[arr[i]]==0)
                mp[arr[i]] = 1;
        }

        int ans = 0;
        for(auto i:mp)
            ans = max(ans,i.second);
        return ans;
    }
};