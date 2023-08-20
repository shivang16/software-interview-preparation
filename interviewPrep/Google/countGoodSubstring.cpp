class Solution {
public:
    int countGoodSubstrings(string s) {
        int k = 3;
        int n = s.size();
        int low=0,high=0;
        unordered_map <char,int> M;
        int ans = 0;
        while(high<n){
            M[s[high]]++;
            if(high-low+1==k){
                if(M.size()==k){
                    ans++;
                }
                M[s[low]]--;
                if(M[s[low]]==0)
                    M.erase(s[low]);
            
                low++;
            }
            high++;
        }
        return ans;
    }
};