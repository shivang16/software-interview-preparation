// https://leetcode.com/problems/detect-squares/submissions
class DetectSquares {
public:
    const static int nax = 1e3 + 1;
    //x, {y, count}
    unordered_map<int, unordered_map<int, int>> countMap;
    DetectSquares() {
        countMap.clear();
    }
    
    void add(const vector<int> &point) {
        int x = point[0];
        int y = point[1];
        if (countMap.find(x) == countMap.end()) countMap[x] = {};
        countMap[x][y] = countMap[x][y] + 1;
    }
    
    int count(const vector<int> &point) {
        int res = 0;
        int x1 = point[0];
        int y1 = point[1];
        //find point below using same X which we have mapped
        for (const auto &entry: countMap[x1]) {
            //to avoid processing the same points and building the
            //square out of them
            int y2 = entry.first;
            if (y2 == y1) continue;
            int diff = abs(y2 - y1);
            //x1 - diff
            int x2 = x1 - diff;
            if (x2 >= 0) {
                res += (countMap[x1][y2] * countMap[x2][y2] * countMap[x2][y1]);
            }
            x2 = x1 + diff;
            if (x2 < 1001)
                res += (countMap[x1][y2] * countMap[x2][y2] * countMap[x2][y1]);
        }
        return res;
    }
};