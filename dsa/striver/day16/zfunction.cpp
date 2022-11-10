// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length(),h = haystack.length();
        if(n>h)
            return -1;
        if(n==h)
            return haystack==needle?0:-1;
        string s = "";
        for(int i=0;i<=h-n;i++){
            s = haystack.substr(i,n);
            if(s==needle)
                return i;
        }
        return -1;
    }
};