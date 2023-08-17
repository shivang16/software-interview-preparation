// https://leetcode.com/problems/my-calendar-ii/description/
class MyCalendarTwo {
public:
    map <int,int> M;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        M[start]++;
        M[end]--;
        int count = 0;
        
        for(auto i:M){
            count+=i.second;
            // cout << i.first << " " << i.second << " " << count << endl;
            if(count>=3){
                M[start]--;
                M[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */