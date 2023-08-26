class Solution {
public:
    bool canBePlaced(vector <int>& v1,vector <int>& v2){
        return v2[0]<=v1[0] && v2[1] <= v1[1] && v2[2] <= v1[2];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &i:cuboids){
            sort(i.begin(),i.end());
        }
        sort(cuboids.begin(),cuboids.end());
        reverse(cuboids.begin(),cuboids.end());
        // for(auto i:cuboids){
        //     for(auto j:i)
        //         cout << j << " ";
        //     cout << endl;
        // }
        int n = cuboids.size();
        vector <int> dp(n,-1);
        for(int i=0;i<n;i++)
            dp[i] = cuboids[i][2];
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(canBePlaced(cuboids[j],cuboids[i])){
                    cout << i << " " << j << endl;
                    dp[i] = max(dp[i],cuboids[i][2]+dp[j]);
                }
            }
        }
        int ans = 0;
        for(auto i:dp)
            ans = max(ans,i);
        return ans;
    }
};