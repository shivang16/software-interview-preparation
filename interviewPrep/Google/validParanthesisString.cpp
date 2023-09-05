// https://leetcode.com/problems/valid-parenthesis-string/submissions/
class Solution {
private: 
    vector <vector <int>> dp;
public:
    bool checkValidity(string &s,int ind,int open){
        if(ind==s.size()){
            return open==0;
        }
        if(open<0) return false;
        if(dp[ind][open]!=-1) return dp[ind][open];
        bool ans;
        if(s[ind]=='(')
            ans =  checkValidity(s,ind+1,open+1);
        else if(s[ind]==')')
            ans = checkValidity(s,ind+1,open-1);
        else{
            ans = checkValidity(s,ind+1,open) || checkValidity(s,ind+1,open+1) || checkValidity(s,ind+1,open-1);
        }
        return dp[ind][open] = ans;
    }
    bool checkValidString(string s) {
        dp.resize(105,vector <int> (105,-1));
        return checkValidity(s,0,0);
    }
};