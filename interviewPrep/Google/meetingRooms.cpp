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
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        map <int,int> M;
        for(auto i:intervals){
            M[i.start]++;
            M[i.end]--;
        }
        int count = 0;
        for(auto i:M){
            count+=i.second;
            // cout << i.first << " " << i.second << " " << count << endl;
            if(count>1)
                return false;
        }
        return true;

    }
};