class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> M;
        int n = s.length();
        int l = 0, r = 0;
        int ans = 0;
        while(r<n && r>=l){
            if(M.find(s[r])!=M.end()){
                ans = max(ans,r-l);
                int ind = M[s[r]];
                while(l<=ind){
                    M.erase(s[l]);
                    l++;
                }
            }
            M[s[r]] = r;
            r++;
        }
        ans = max(ans,r-l);
        return ans;
    }
};