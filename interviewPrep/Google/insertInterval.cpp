class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector <int>> ans;
        int l = intervals[0][0];
        int r = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(r>=intervals[i][0]){
                r = max(r,intervals[i][1]);
            }else{
                ans.push_back({l,r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        ans.push_back({l,r});
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        return merge(intervals);
    }
};