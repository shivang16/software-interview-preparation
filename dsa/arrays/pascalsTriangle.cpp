// https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> ans;
        vector <int> first; first.push_back(1);
        ans.push_back(first);
        for(int i=1;i<numRows;i++){
            vector <int> temp;
            temp.push_back(1);
            for(int j=1;j<=i-1;j++){
                int val = ans[i-1][j-1]+ans[i-1][j];
                temp.push_back(val);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};