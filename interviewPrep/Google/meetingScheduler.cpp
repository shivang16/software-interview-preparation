// https://www.lintcode.com/problem/3653/
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
     * @param slots1: The availability schedule of one.
     * @param slots2: The availability schedule of one.
     * @param duration: The expected duration of the meeting.
     * @return: The earliest and appropriate meeting time in the interval for them.
     */
    Interval earliestAppropriateDuration(vector<Interval> &slots1, vector<Interval> &slots2, int duration) {
        map <int,int> mp;
        for(auto i:slots1){
            mp[i.start]++;
            mp[i.end]--;
        }
        for(auto i:slots2){
            mp[i.start]++;
            mp[i.end]--;
        }
        Interval ans(-1,-1);
        
        int count = 0,l=-1;
        for(auto i:mp){
            count+=i.second;
            if(l!=-1){
                int diff = i.first-l;
                if(diff>=duration){
                    return Interval(l,l+duration);
                }else{
                    l = -1;
                }
            }
            if(count==2){
                l = i.first;
            }
        }
        return ans;
        
        // --- write your code here ---
    }
};