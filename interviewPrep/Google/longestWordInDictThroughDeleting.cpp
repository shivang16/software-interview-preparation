// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
class Solution {
public:
    bool isSubSeq(string s,string t){
        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j==t.size();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(auto i:dictionary){
            if(isSubSeq(s,i)){
                if(ans.size()<i.size()){
                    ans = i;
                }else if(ans.size()==i.size())
                    ans = min(ans,i);
            }
        }
        return ans;
    }
};