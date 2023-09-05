// https://leetcode.com/problems/my-calendar-iii
class MyCalendarThree {
public:
    map <int,int> M;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        M[start]++;
        M[end]--;
        int count = 0;
        int mx = 0;
        for(auto i:M){
            count+=i.second;
            mx = max(mx,count);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */