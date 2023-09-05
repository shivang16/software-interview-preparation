// https://leetcode.com/problems/minimum-time-to-complete-all-tasks/submissions/
class Solution {
public:
    static bool comp(vector <int> &t1,vector <int> &t2){
        return t1[1]<t2[1];
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        vector <int> timeOn(20001,0);
        sort(tasks.begin(),tasks.end(),comp);
        int ans = 0;
        for(int i=0;i<tasks.size();i++){
            int start = tasks[i][0];
            int remainingDuration = tasks[i][2];
            int end = tasks[i][1];
            cout << start << " " << end << " " << remainingDuration << endl;
            int time = start;
            while(time <= end && remainingDuration){
                if(timeOn[time]==1)
                    remainingDuration--;
                time++;
            }

            while(remainingDuration){
                if(timeOn[end]!=1){
                    timeOn[end] = 1;
                    remainingDuration--;
                    ans++;
                }
                end--;
            }
        }
        return ans;
    }
};