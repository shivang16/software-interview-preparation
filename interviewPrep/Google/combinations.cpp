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


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector <vector <int>> ans;
        for(int i=0;i<(1<<n);i++){
            if(__builtin_popcount(i)==k){
                vector <int> temp;
                int j = 0;
                while(j<n){
                    if(i & (1<<j)) temp.push_back(j+1);
                    j++;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};