// https://www.interviewbit.com/problems/2-sum/
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map <int,int> M;
    vector <int> ans;
    for(int i=0;i<A.size();i++){
        if(M.find(B-A[i])!=M.end()){
            ans.push_back(M[B-A[i]]);
            ans.push_back(i+1);
            // cout << M[B-A[i]] << " " << i << endl;
            break;
        }
        if(M.find(A[i])==M.end())
            M[A[i]] = i+1;
        
    }
    return ans;
}
