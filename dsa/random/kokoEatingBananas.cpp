class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l=1,r=0;
        for(auto i:piles)
            r = max(i,r);
        int ans=INT_MAX;
        while(r>=l){
            int mid=l+(r-l)/2;
            long count = 0;
            for(auto i:piles){
                double res=(i*1.0)/mid;
                count+=(ceil(res));
            }
            if(count<=h){
                ans = min(ans,mid);
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};