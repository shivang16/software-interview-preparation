// https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution {
public:
    int countVowelStrings(int n) {
    {
        int count=0;
        vector<int> dp(5,1);
        while(--n)
        {
            for(int i=3;i>=0;i--)
            {
                dp[i]+=dp[i+1];
            }
        }
        for(auto x:dp)
        {
            count+=x;
        }
        return count;
    }
};