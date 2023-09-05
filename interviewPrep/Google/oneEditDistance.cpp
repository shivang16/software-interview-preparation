// https://www.lintcode.com/problem/640/
class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        if(s.size()<t.size()) return isOneEditDistance(t,s);
        if(s==t) return false;
        int sizeDiff = s.size()-t.size();
        if(sizeDiff>=2) return false;
        if(sizeDiff==0){
            int count = 0;
            int i = 0;
            while(i<s.size()){
                if(s[i]!=t[i])
                    count++;
                i++;
            }
            return count==1;
        }else{
            int count = 0;
            int i = 0, j=0;
            while(i<s.size() && j<t.size()){
                if(s[i]!=t[j]){
                    i++;
                    count++;
                }else{
                    i++;
                    j++;
                }
            }
            return count<=1;
        }
        // write your code here
    }
};