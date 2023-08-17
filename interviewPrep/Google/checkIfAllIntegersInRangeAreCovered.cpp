// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int M[60] = {};
        for(auto i:ranges){
            M[i[0]]++;
            M[i[1]+1]--;
        }
        int count = 0;
        for(int i=1;i<=50;i++){
            count+=M[i];
            if(i>=left && i<=right && count<=0) return false;
        }
        return true;
    }
};