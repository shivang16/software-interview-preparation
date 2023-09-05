// https://leetcode.com/problems/maximum-split-of-positive-even-integers/solutions/1783191/c-easy-simulation-o-maximumnumbers-time-o-1-space/
class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        if(n&1)return {};
        long long int x = 2,sum=0;
        vector<long long int> ans;
        while(sum+x<=n){
            sum += x;
            ans.push_back(x);
            x += 2;
        }
        ans.back()+=(n-sum);
        return ans;
    }
};