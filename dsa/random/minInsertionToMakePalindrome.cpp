class Solution {
public:
    int minInsertions(string s){
    int n = s.length();
	//initializing with 1 because each element is palindrome itself
    vector<vector<int>> dp(n, vector<int>(n, 1));
	//to find longest palindrome sub sequence
    for(int gp=1; gp<n; gp++){
      for(int i=0; i<n-gp; i++){
        int j=i+gp;
		//if the size of string is 2 and both elements are same 
        if(gp==1 and s[i]==s[j]) dp[i][j] = 2;
        else if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1]+2;
        else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
      }
    }
	//other elements should be added to make the string palindrome
    return n-dp[0][n-1];
  }
};