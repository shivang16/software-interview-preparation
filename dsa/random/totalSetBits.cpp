int findLargestPower(int n)
{
    int x = 0;
    while ((1 << x) <= n)
        x++;
    return x - 1;
}
int Solution::solve(int A) {
    long long  int ans=0;
   
   int bits=log10(A)/log10(2);
   //cout<<bits;
   for(int i=0;i<=bits;i++)
   {
       int c=pow(2,i),cnt=0;
       int set=(A+1)/c;
       cnt=(set/2)*c;
       int incomp=(A+1)%c;
       if(set%2!=0) cnt+=incomp;
       
       ans+=cnt;
   }
    return ans%1000000007;
}
