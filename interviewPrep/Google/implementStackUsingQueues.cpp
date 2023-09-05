// https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
public:
    queue <int> Q;
    MyStack() {
        
    }
    
    void push(int x) {
        int sz = Q.size();
        Q.push(x);
        while(sz--){
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    int pop() {
        int x = Q.front();
        Q.pop();
        return x;
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return  Q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */