//https://leetcode.com/problems/get-maximum-in-generated-array/
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1)
            return n;
        int A[n+1];
        A[0] = 0;
        A[1] = 1;
        int mx = 1;
        for(int i=2;i<=n;i++){
            if(i%2==0){
                A[i] = A[i/2];
            }else{
                A[i] = A[i/2]+A[1+i/2];
            }
            mx = max(A[i],mx);
        }
        return mx;
    }
};