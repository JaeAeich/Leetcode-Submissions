class MyStack {
public:
    queue<int> q1;
    
    MyStack() {
        
    }
    
    void push(int x) {
        // pushin the ele at the end of queue
        q1.push(x);
        int n=q1.size();
        // pushing the ele the front
        for(int i=0;i<n-1;i++){
            int x=q1.front();
            q1.pop();
            q1.push(x);
        }
    }
    
    int pop() {
        int val= q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
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