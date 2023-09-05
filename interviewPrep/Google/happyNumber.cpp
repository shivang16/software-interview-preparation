// https://leetcode.com/problems/happy-number/
class Solution {
public:
    unordered_set <int> S;
    bool getAns(int n){
        if(n==1)
            return true;
        if(n==2||n==3 || S.find(n)!=S.end())
            return false;
        S.insert(n);
        int val = 0;
        while(n!=0){
            int rem = n%10;
            val += pow(rem,2);
            n/=10;
        }
        return getAns(val);
    }
    bool isHappy(int n) {
        S.clear();
        return getAns(n);
        
    }
};