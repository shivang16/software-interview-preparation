// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        priority_queue <int> Q;
        for(auto i:nums)
            Q.push(i);
        int mod = pow(10,9)+7;
        int ans = 0;
        int M[100005] = {};
        for(auto i:requests){
            M[i[0]]++;
            M[i[1]+1]--;
        }
        priority_queue <int> Q2;
        int count = 0;
        for(auto i:M){
            count+=i;
            // cout << i.first << " " << i.second << " " << count << endl;
            if(count>0){
                Q2.push(count);
            }
        }
        while(!Q2.empty()){
            int temp = ((long long)Q.top()*Q2.top())%mod;class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        priority_queue <int> Q;
        for(auto i:nums)
            Q.push(i);
        int mod = pow(10,9)+7;
        int ans = 0;
        int M[100005] = {};
        for(auto i:requests){
            M[i[0]]++;
            M[i[1]+1]--;
        }
        priority_queue <int> Q2;
        int count = 0;
        for(auto i:M){
            count+=i;
            // cout << i.first << " " << i.second << " " << count << endl;
            if(count>0){
                Q2.push(count);
            }
        }
        while(!Q2.empty()){
            int temp = (Q.top()*Q2.top())%mod;
            ans = (ans+temp)%mod;
            Q.pop();
            Q2.pop();
        }
        return ans;
    }
};
            ans = (ans+temp)%mod;
            Q.pop();
            Q2.pop();
        }
        return ans;
    }
};