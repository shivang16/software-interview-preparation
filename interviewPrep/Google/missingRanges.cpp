// https://www.lintcode.com/problem/641/record
class Solution {
public:
    /**
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        // write your code here
        vector <string> ans;
        long long l = lower, h = l;
        for(long long i:nums){
            h = i-1;
            if(l==i){
                l = i+1;
            }
            if(h>=l && h<=upper){
                if(h==l){
                    ans.push_back(to_string(h));
                }
                else{
                    ans.push_back(to_string(l)+"->"+to_string(h));
                }
                l = i+1;
            }
        }
        h = upper;
        if(h==l){
            ans.push_back(to_string(h));
        }
        else if(h>l){
            ans.push_back(to_string(l)+"->"+to_string(h));
        }
        return ans;
    }
};