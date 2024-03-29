// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/class Solution {
public:
    static bool comp(vector <int> &v1,vector <int> &v2){
        return v1[1]<v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int ans = 1;
        int end = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){
                end = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};