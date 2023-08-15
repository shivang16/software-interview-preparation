// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// https://leetcode.com/problems/first-bad-version/description/
class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1)
            return 1;
        int l = 1;
        int h = n;
        long mid;
        long ans;
        while(h>=l){
            mid = ((long)h+l)/2;
            if(isBadVersion(mid)){
                h = mid-1;
                ans = mid;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};