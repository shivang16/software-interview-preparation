class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, n= s.size();
        unordered_map <char,int> M;
        int low = 0, high = 0,freq;
        while(high<n){
            M[s[high]]++;
            freq = max(freq,M[s[high]]);
            if(high-low+1-freq>k){
                M[s[low]]--;
                low++;
            }
            ans = max(ans,high-low+1);
            high++;
        }
        return ans;
    }
};