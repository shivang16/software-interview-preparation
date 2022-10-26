// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A) {
    int sum = 0;
    int ans = INT_MIN;
    for(auto i:A){
        sum+=i;
        ans = max(ans,sum);
        if(sum<0)
            sum=0;
    }
    return ans;
}
