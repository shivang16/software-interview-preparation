// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/submissions/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map <long long,int>M;
        long long sum = 0;
        M[0] = -1;
        for(int i=0;i<arr.size();i++){
            sum=(long long)(sum+arr[i]);
            M[sum] = i;
        }
        sum = 0;
        int leftSize = INT_MAX, ans=INT_MAX;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(M.find(sum-target)!=M.end()){
                leftSize = min(leftSize,i-M[sum-target]+1);
            }

            if(M.find(sum+target)!=M.end() && leftSize!=INT_MAX){
                ans = min(ans,(M[sum+target]-i-1)+leftSize);
            }
        }
        return ans==INT_MAX?-1:ans;

    }
};