int Solution::canJump(vector<int> &A) {
    int mx = 0;
    for(int i=0;i<A.size();i++)
    {
        if(i<=mx)
            mx = max(mx,A[i]+i);
        else
            return false;
    }
    return mx>=A.size()-1;
}
