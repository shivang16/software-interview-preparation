// https://leetcode.com/problems/find-all-anagrams-in-a-string/
class Solution {
public:
    bool isAnagram(int A[],int B[]){
        for(int i=0;i<26;i++){
            if(A[i]!=B[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size(), ps = p.size();
        int low = 0, high = 0;
        int P[26] = {}, S[26] = {};
        for(auto i:p){
            P[i-'a']++;
        }
        vector <int> ans;
        while(high<ss){
            S[s[high]-'a']++;
            if(high-low+1==ps){
                if(isAnagram(S,P)){
                    ans.push_back(low);
                }
                S[s[low]-'a']--;
                low++;
            }
            high++;
        }
        return ans;
    }
};