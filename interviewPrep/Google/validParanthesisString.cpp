class Solution {
    int dp[101][101];
    bool solve(string &s, int index, int open){
        if(index == s.size()){
            return open == 0;
        }
        
        if(dp[index][open] != -1){
            return dp[index][open];
        }
        
        if(s[index] == '('){
            return dp[index][open] = solve(s, index + 1, open + 1);
        }
        else if(s[index] == ')'){
            return dp[index][open] = open != 0 && solve(s, index + 1, open - 1);
        }
        else{
            return dp[index][open] = solve(s, index + 1, open + 1) 
                || open != 0 && solve(s, index + 1, open - 1)
                || solve(s, index + 1, open);
        }
    }
public:
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0);
    }
};