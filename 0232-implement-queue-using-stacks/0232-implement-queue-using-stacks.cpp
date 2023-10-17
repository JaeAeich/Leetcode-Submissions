class MyQueue {
private:
    stack<int> s;
    int top = -1;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s.empty()){
            top = x;
        }
        s.push(x);
    }
    
    int pop() {
        stack<int> temp;
        while(!s.empty()){
            int val = s.top();
            temp.push(val);
            s.pop();
        }
        int ret = top;
        if(!temp.empty()) temp.pop();
        if(!temp.empty()) top = temp.top();
        while(!temp.empty()){
            int val = temp.top();
            s.push(val);
            temp.pop();
        }
        return ret;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */