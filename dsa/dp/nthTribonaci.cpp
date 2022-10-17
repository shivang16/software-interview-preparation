class Solution {
public:
    int tribonacci(int n) {
        if(n<=1)
            return n;
        if(n==2)
            return 1;
        int F[n+1];
        F[0] = 0;F[1]=1;F[2]=1;
        for(int i=3;i<=n;i++)
            F[i] = F[i-1]+F[i-2]+F[i-3];
        return F[n];
    }
};