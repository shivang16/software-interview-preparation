class RLEIterator {
    private: 
        deque <pair <int,int>> dq;
public:
    RLEIterator(vector<int>& encoding) {
        for(int i=0;i<encoding.size();i+=2){
            if(encoding[i]!=0)
                dq.push_back({encoding[i],encoding[i+1]});
        }
    }
    int next(int n) {
        int x = n;
        while(dq.size()){
            int left = dq.front().first;
            int tp = dq.front().second;
            dq.pop_front();
            if(x>left){
                x-=left;
            }else if(x==left){
                return tp;
            }else{
                left-=x;
                dq.push_front({left,tp});
                return tp;
            }
        } 
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */