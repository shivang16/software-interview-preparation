vector<int> Solution::prevSmaller(vector<int> &A) {
    stack <int> S;
    int n = A.size();
    vector <int> ans;
    for(int i=0;i<n;i++){
        while(!S.empty() && A[i]<=S.top())
            S.pop();
        if(S.empty())
            ans.push_back(-1);
        else
            ans.push_back(S.top());
        S.push(A[i]);
    }    
    return ans;
}
