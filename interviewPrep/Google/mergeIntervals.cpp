// https://leetcode.com/problems/merge-intervals/description/
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end());
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
// };

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map <int,int> M;
        vector <vector <int>> ans;
        for(auto i:intervals){
            M[i[0]]++;
            M[i[1]]--;
        }
        int count = 0;
        int l = -1;
        for(auto i:M){
            count+=i.second;
            if(l==-1){
                l = i.first;
            }
            if(count<=0){
                vector <int> temp;
                temp.push_back(l);
                temp.push_back(i.first);
                ans.push_back(temp);
                count=0;
                l = -1;
            }
        }
        // if(l!=-1){
        //     ans.push_back()
        // }
        return ans;
    }
};