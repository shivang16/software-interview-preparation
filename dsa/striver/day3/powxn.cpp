class Solution {
public:
    double myPow(double x, int n) {
        if(x==1||x==-1)
            return n%2==0?1:x;
        if(n<=-2147483648)
            return 0;
        double ans = 1;
        double res = 1;
        bool flag = n>0;
        n = abs(n);
        
        while(n>0){
            if(n%2==0){
                    x*=x;
                n/=2;
            }else{
                    res*=x;
                n--;
            }
        }
        
        return flag?res:1/res;    

    }
};