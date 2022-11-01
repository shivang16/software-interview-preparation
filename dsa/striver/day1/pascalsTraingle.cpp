class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
		
		//create vector of triangle size
        for(int i=0;i<numRows;i++){
            res[i].resize(i+1);
        }
        
		//assign 1st and last element of each row to 1
        for(int i=0;i<numRows;i++){
            res[i][0]=1;
            res[i][i]=1;
        }
        
		//just perform the operation told in questions description
		//   res[3][1] = res[2][0] + res[2][1]
        for(int i=2;i<numRows;i++){
            for(int j=1;j<i;j++){
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }
};