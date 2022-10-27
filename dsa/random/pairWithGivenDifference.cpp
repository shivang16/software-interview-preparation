// https://www.interviewbit.com/problems/pair-with-given-difference/
int Solution::solve(vector<int> &A, int B) {
    unordered_map <int,int> M;
    for(auto i:A){
        M[i]++;      
    }
    for(auto i:A){
        if(M.find(i+B)!=M.end()){
            if(i+B==i){
                return M[i+B]>1;
            }
            else return 1;
        }
            
    }
    return 0;
}
