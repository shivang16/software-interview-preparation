int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map <int,int> M;
    int x = 0,ans=0;
    for(int i=0;i<n;i++){
        x^=A[i];
        if(x==B)
            ans++;
        if(M.find(x^B)!=M.end())
            ans+=M[x^B];
        M[x]++;
    }
    return ans;
}
