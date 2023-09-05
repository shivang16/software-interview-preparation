// https://leetcode.com/problems/range-sum-query-2d-immutable/description/
class NumMatrix {
    private: 
        vector <vector <int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n=matrix[0].size();
        prefix.resize(m+1,vector <int> (n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]+matrix[i-1][j-1]-prefix[i-1][j-1];
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++)
        //         cout << prefix[i][j] << " ";
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2+1][col2+1]-prefix[row1][col2+1]-prefix[row2+1][col1]+prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */