// https://leetcode.com/problems/number-of-matching-subsequences/description/
class Solution {
public:
    bool isSub(string word, string &s) {
        int n = s.size();
        int j = word.size()-1;
        for(int i=n-1;i>=0 && j>=0;i--){
            if(word[j]==s[i]){
                j--;
            }
        }
        return j<0;
    }

    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map <string,int> M;
        for(auto i:words){
            M[i]++;
        }
        for(auto i:M){
            if(isSub(i.first,s))
                count+=i.second;
        }
        return count;
    }1;
        for(int i=n-1;i>=0)
};