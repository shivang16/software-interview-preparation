// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0,r=0;
        int cnt=0;
        int a[256]={0};
        while(r<n){
            if(a[s[r]]==0){
                a[s[r]]++;
                cnt=max(cnt,r-l+1);
                r++;
            }
            else{
                a[s[l]]--;
                l++;
                    
            }
        }
        return cnt;
    }
};