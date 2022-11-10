class Solution {
public:
    bool isAnagram(string s, string t) {
        int S[26] = {0};
        int T[26] = {0};
        for(auto i:s)
            S[i-'a']++;
        for(auto i:t)
            T[i-'a']++;
        for(int i=0;i<26;i++)
            if(S[i]!=T[i])
                return false;
        return true;
    }
};