// https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/
class Solution {
public:
    long long calculateCost(vector <pair <int,int>> &Wg,int target){
        long long ans = 0;
        for(auto i:Wg){
            long long diff = (long long)abs(target-i.first);
            long long prod = (long long)diff*i.second;
            ans += prod;
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector <pair <int,int>> Wg;
        for(int i=0;i<nums.size();i++){
            Wg.push_back({nums[i],cost[i]});
        }
        sort(Wg.begin(),Wg.end());  
        long long low = Wg[0].first, high = Wg[nums.size()-1].first;
        if(low==high) return 0;

        long long ans = INT_MAX;
        while(high>=low){
            int mid = (low+high)/2;

            long long cost1 = calculateCost(Wg,mid);

            long long cost2 = calculateCost(Wg,mid+1);
            ans = min(cost1,cost2);

            if(cost1>cost2){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};