class MinStack {
public:
    

    stack <pair <int,int>> S;
    MinStack() {
    }
    
    void push(int val) {
        if(S.empty()){
            S.push({val,val});
        }else{
            int crntMin = S.top().second;
            if(crntMin>val){
                S.push({val,val});
            }else{
                S.push({val,crntMin});
            }
        }
    }
    
    void pop() {
        S.pop();
    }
    
    int top() {
        return S.top().first;
    }
    
    int getMin() {
        return S.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */