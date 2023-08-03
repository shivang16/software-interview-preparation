vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map <int,int> M;
    int l=-1,r=0;
    int n = A.size();
    vector <int> ans;
    if(B>n) return ans;
    while(r<n){
        M[A[r]]++;
        if(r-l==B){
            ans.push_back(M.size());
            l++;
            if(M[A[l]]==1){
                M.erase(A[l]);
            }else{
                M[A[l]]--;
            }
        }
        r++;
    }
    return ans;
}
