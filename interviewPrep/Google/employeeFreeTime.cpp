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
     * @param schedule: a list schedule of employees
     * @return: Return a list of finite intervals 
     */
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {
        // Write your code here
        vector <Interval> ans;
        map <int,int> M;
        for(auto i:schedule){
            for(int j=0;j<i.size();j+=2){
                M[i[j]]++;
                M[i[j+1]]--;
            }
        }
        int l = -1;
        int count = 0;
        for(auto i:M){
            count+=i.second;
            if(count==0){
                l = i.first;
            }else{
                if(l!=-1){
                    ans.push_back(Interval(l,i.first));
                    l = -1;
                }
            }
            
        }
        return ans;
    }
};
