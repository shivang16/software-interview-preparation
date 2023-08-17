class MyCalendar {
public:
    map <int,int> M;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        M[start]++;
        M[end]--;
        int count = 0;
        
        for(auto i:M){
            count+=i.second;
            // cout << i.first << " " << i.second << " " << count << endl;
            if(count>=2){
                M[start]--;
                M[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */