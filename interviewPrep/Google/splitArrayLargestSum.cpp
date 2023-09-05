// https://leetcode.com/problems/split-array-largest-sum/description/
class Solution {
public:
    bool canSplit(vector <int>& nums,int k,int m){
        int sum = 0;
        int count = 0;
        for(auto i:nums){
            sum+=i;
            if(sum>k){
                count++;
                sum = i;
            }
        }
        if(count>=m)
            return true;
        return false;
        
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int l=INT_MIN,r=0;
        for(auto i:nums){
            l = max(l,i);
            r+=i;
        }
        int ans = l-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(canSplit(nums,mid,m)){
                l = mid+1;
                ans = mid;
            }else{
                r = mid-1;
            }
        }
        return ans+1;
    }
};