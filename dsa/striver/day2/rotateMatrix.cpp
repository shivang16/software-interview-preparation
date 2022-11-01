// https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& M) {
        int n = M.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)
                swap(M[i][j],M[j][i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++)
                swap(M[i][j],M[i][n-j-1]);
        }
    }
};