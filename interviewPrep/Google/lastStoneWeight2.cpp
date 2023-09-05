// https://leetcode.com/problems/last-stone-weight-ii/submissions/
class Solution {
    int minDiffSubset(vector<int>& stones, int n, int sum) {
        vector<vector<bool>> t(n+1, vector<bool>(sum/2+1));
        for(int col = 0; col<sum/2+1; col++)
            t[0][col] = false;
        for(int row = 0; row<n+1; row++)
            t[row][0] = true;
        
        for(int i = 1; i<n+1; i++) {
            for(int j = 1; j<sum/2+1; j++) {
                if(stones[i-1] <= j) {
                    t[i][j] = t[i-1][j-stones[i-1]] || t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        int i = sum/2;
        for(; i>=0; i--) {
            if(t[n][i] == true)
                break;
        }
        return (sum-2*i);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for(int i = 0;i<n;i++){
            sum+=stones[i];
        }
        return minDiffSubset(stones, n, sum);
    }
};