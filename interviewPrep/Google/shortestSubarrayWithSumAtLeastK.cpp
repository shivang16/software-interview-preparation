// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/solutions/3341433/o-n-explained-monotonic-stack-prefix-sum-c/
class Solution {
public:
    typedef long long ll;
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        priority_queue <pair <ll,int>,vector <pair<ll,int>>,greater <pair <ll,int>>> Q;
        int ans = INT_MAX;
        ll sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum>=K)
                ans = min(ans,i+1);
            while(!Q.empty() && sum - Q.top().first >=K)
            {
                auto x = Q.top();
                ans = min(ans,i-x.second);
                Q.pop();
            }
            Q.push({sum,i});
        }
        return ans==INT_MAX?-1:ans;
    }
    };