int Solution::majorityElement(const vector<int> &A) {
    int el = A[0];
    int nt = 1;
    for(int i=1;i<A.size();i++)
    {
        if(A[i]==el)
            nt++;
        else{
            if(nt<1){
                el = A[i];
                nt = 1;
            }else{
                nt--;
            }
        }
    }
    return el;
}
