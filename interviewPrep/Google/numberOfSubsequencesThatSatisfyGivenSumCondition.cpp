#define ll long long
class Solution {
public:
    ll inf = 1e9+7;
    ll bin(ll a, ll b)
    {
        ll ans = 1;
        while(b)
        {
            if(b&1) ans = (ans * a)%inf;
            a = (a * a)%inf;
            b >>= 1;
        }
        return ans;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int  n = size(nums),i = 0, ans = 0, j= n-1;
        while(i<=j)
        {
            if(nums[i] + nums[j] > target)--j;
            else ans = (ans + bin(2, j-i)) %inf, ++i;
        }
        return ans;
    }
};
// Upvote if you like the solution!!! 👍👍