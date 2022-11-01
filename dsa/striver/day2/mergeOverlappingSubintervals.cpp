// https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector <vector <int>> ans;
        int n = intervals.size();
        for(int i=0;i<n;){
            int l = intervals[i][0];
            int r = intervals[i][1];
            while(i<n&& (r<=intervals[i][1]&&r>=intervals[i][0]||(r>intervals[i][1]))){
                r = max(r,intervals[i][1]);
                i++;
            }
            vector <int> temp = {l,r};
            ans.push_back(temp);
        }
        return ans;
    }
};