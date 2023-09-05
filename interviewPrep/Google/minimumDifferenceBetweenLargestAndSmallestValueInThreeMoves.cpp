// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
#define ll long long
class Solution {
public:
    int minDifference(vector<int>& A) {
        int ans = INT_MAX;
        int l = A.size();
        if(l<=3)
            return 0;
        sort(A.begin(),A.end());
        ans = min(ans,A[l-4]-A[0]);
        ans = min(ans,A[l-1]-A[3]);
        ans = min(ans,A[l-3]-A[1]);
        ans = min(ans,A[l-2]-A[2]);
        return ans;
        
        
    }
};