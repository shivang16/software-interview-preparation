// https://leetcode.com/problems/next-greater-element-iii/description/
class Solution {
public:
    int nextGreaterElement(int n) {
        if(n<10)
            return -1;
        string s = to_string(n);
        bool val = next_permutation(s.begin(),s.end());
        if(!val)
            return -1;
        long long  m = 0;
        for(int i=0;i<s.length();i++)
           m = m*10+(s[i]-'0');
        if(m>INT_MAX)
            return -1;
        
        return (int)(m);
        // return 0;
    }
};