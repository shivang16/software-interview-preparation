// https://leetcode.com/problems/minimum-area-rectangle
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        using pi = pair<int,int>;
        vector<pi> pointList;
        set<pi> pointSet;
        for (auto& p: points) {
            pointList.push_back({p[0],p[1]});
            pointSet.insert({p[0],p[1]});
        }
        sort(pointList.begin(),pointList.end());
        
        int totalPoints = pointList.size();
        int result = INT_MAX;
        for (int i = 0; i < totalPoints-3; i++) {
            int x1 = pointList[i].first;
            int y1 = pointList[i].second;
            for (int j = i+1; j < totalPoints;) {
                int x2 = pointList[j].first;
                int y2 = pointList[j].second;
                
                // found out diagnoal point opposite to left most base point
                if ((x1 != x2) && (y1 != y2) && (x1 < x2) && (y1 < y2)) {
                    pi leftPoint = make_pair(x1,y2);
                    pi rightPoint = make_pair(x2,y1);
                    // if mirror point exists which means it can form a rectangle
                    if (pointSet.count(leftPoint) && pointSet.count(rightPoint)) {
                        // calcuate the area  then and update the minmumm
                        int curArea = (x2-x1)*(y2-y1);
                        result = min(result,curArea);
                        j++;
                        // skip all the points for the given x as minimumm area with same
                        // and least Y is already computed.
                        while(j < totalPoints && (pointList[j].first == x2))
                            j++;
                        continue;
                    }
                }
                j++;
            }
        }
        return result == INT_MAX ? 0 : result;
        
    }
};