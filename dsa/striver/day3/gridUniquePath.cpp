// https://leetcode.com/problems/unique-paths/submissions/
class Solution {
public:
    long long ncr(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
    int uniquePaths(int m, int n) {
        return ncr(m+n-2,n-1);
    }
};
