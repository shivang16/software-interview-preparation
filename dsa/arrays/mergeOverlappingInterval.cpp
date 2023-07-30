// https://leetcode.com/problems/merge-intervals/submissions/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector <vector <int>> ans;
        for(int i=0;i<n;){
            int b = intervals[i][0];
            int e = intervals[i][1];
            int j = i+1;
            while(j<n){
                if(intervals[j][0]<=e){
                    e = max(e,intervals[j][1]);
                    j++;
                }else{
                    break;
                }
            }
            vector <int> temp;
            temp.push_back(b);
            temp.push_back(e);
            ans.push_back(temp);
            i=j;
        }
        return ans;
    }
};