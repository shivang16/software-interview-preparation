// https://leetcode.com/problems/longest-string-chain/description
class Solution {
public:
    bool isPredecessor(string s1,string s2){
        int l1 = s1.size(), l2 = s2.size();
        if(l2!=l1+1) return false;
        bool misMatched = false;
        int j=0;
        for(int i=0;i<l2;i++){
            if(s1[j]!=s2[i]){
                if(misMatched)
                    return false;
                else{
                    misMatched = true;
                }
            }else{
                j++;
            }
        }
        return true;
    }

    bool static comparator(string word1,string word2){
        return word1.size()<word2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comparator);
        vector <int> dp(n,1);
        int ans = 1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(isPredecessor(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
        
    }
};