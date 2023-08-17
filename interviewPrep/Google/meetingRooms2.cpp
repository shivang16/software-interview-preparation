/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        map <int,int> Mp;
        for(auto i:intervals){
            Mp[i.start]++;
            Mp[i.end]--;
        }
        int ans = 0;
        int count = 0;
        for(auto i:Mp){
            count+=i.second;
            ans = max(ans,count);
        }
        return ans;

    }
};