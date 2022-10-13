class MinStack {
public:
    stack<int> s;
    stack<int> min;
    
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(min.empty() || min.top()>=val) min.push(val);
        s.push(val);
    }
    
    void pop() {
        if(s.top()==min.top()) min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
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