// https://leetcode.com/problems/insert-interval/submissions/

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector <vector <int>> ans;
//         int l = intervals[0][0];
//         int r = intervals[0][1];
//         for(int i=1;i<intervals.size();i++){
//             if(r>=intervals[i][0]){
//                 r = max(r,intervals[i][1]);
//             }else{
//                 ans.push_back({l,r});
//                 l = intervals[i][0];
//                 r = intervals[i][1];
//             }
//         }
//         ans.push_back({l,r});
//         return ans;
//     }
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         intervals.push_back(newInterval);
//         sort(intervals.begin(),intervals.end());
//         return merge(intervals);
//     }
// };


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map <int,int> mp;
        for(auto i:intervals){
            mp[i[0]]++;
            mp[i[1]]--;
        }
        mp[newInterval[0]]++;
        mp[newInterval[1]]--;
        vector <vector <int>> ans;
        int l = -1,sum = 0;
        for(auto i:mp){
            sum+=i.second;
            if(l==-1){
                l = i.first;
            }
            if(sum==0){
                ans.push_back({l,i.first});
                l = -1;
            }
        }
        return ans;
    }
};