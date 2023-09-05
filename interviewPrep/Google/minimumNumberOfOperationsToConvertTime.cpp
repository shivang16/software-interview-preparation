class Solution {
public:
    int getTime(string time){
        int timeStamp = 0;
        string hh = time.substr(0,2);
        string mm = time.substr(3,2);
        timeStamp = stoi(hh)*60+stoi(mm);
        return timeStamp;
    }
    int convertTime(string current, string correct) {
        int time1 = getTime(current);
        int time2 = getTime(correct);
        // cout << time1 << " " << time2 << endl;
        if(time1>time2){
            time2+=24*60;
        }
        int diff = time2-time1;
        // cout << diff << endl;
        int count = 0;
        count+=diff/60;
        diff%=60;
        // cout << count << " " << diff << endl;
        count+=diff/15;
        diff%=15;
        // cout << count << " " << diff << endl;
        count+=diff/5;
        diff%=5;
        // cout << count << " " << diff << endl;
        count+= diff;
        // cout << count << " " << diff << endl;
        return count;
    
    }
};