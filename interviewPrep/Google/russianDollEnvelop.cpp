class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),comp);

        int n = env.size();
        vector <int> lis;
        for(int i=0;i<n;i++){
            int ele = env[i][1];
            int ind = lower_bound(lis.begin(),lis.end(),ele)-lis.begin();
            if(ind>=lis.size()) lis.push_back(ele);
            else lis[ind] = ele;
        }
        return lis.size();
        
    }
};

// 2 3
// 