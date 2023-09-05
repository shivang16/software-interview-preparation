// https://www.lintcode.com/problem/386/
class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        if(k==0) return 0;
        unordered_map <char,int> Mp;
        int n = s.size();
        int l = 0, r = 0;
        int ans = 0;
        while(r<n){
            Mp[s[r]]++;
            while(l<r && Mp.size()>k){
                Mp[s[l]]--;
                if(Mp[s[l]]==0)
                    Mp.erase(s[l]);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};