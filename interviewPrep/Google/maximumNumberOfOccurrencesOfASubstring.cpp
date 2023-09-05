// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/submissions/
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string,int> mp;
        for(int sz=minSize;sz<=minSize;sz++){
            int l = 0, r = 0;
            unordered_map <char,int> freqMp;
            int count = 0;
            while(r<n){
                freqMp[s[r]]++;
                if(freqMp[s[r]]==1)
                    count++;
                if(r-l+1==sz){
                    if(count<=maxLetters)
                        mp[s.substr(l,r-l+1)]++;
                    freqMp[s[l]]--;
                    if(freqMp[s[l]]==0)
                        count--;
                    l++;
                }
                r++;
            }
        }

        int ans = 0;
        for(auto i:mp){
            ans = max(ans,i.second);
        }
        return ans;
    }
};