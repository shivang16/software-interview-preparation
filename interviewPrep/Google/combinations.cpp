class Solution {
public:
    void getCombination(int n,int k,vector <int> &temp,vector <vector <int>>& ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(n<=0) return;
        temp.push_back(n);
        getCombination(n-1,k-1,temp,ans);
        temp.pop_back();
        getCombination(n-1,k,temp,ans);

    }
    vector<vector<int>> combine(int n, int k) {
        vector <vector <int>> ans;
        vector <int> temp;
        getCombination(n,k,temp,ans);
        return ans;
    }
};