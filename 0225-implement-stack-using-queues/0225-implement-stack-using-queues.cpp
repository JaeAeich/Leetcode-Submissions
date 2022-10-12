class MyStack {
public:
    queue<int> q;
    queue<int> temp;
    
    MyStack() {
        
    }
    
    void push(int x) {
        temp.push(x);
        while(!q.empty()){
            int val=q.front();
            temp.push(val);
            q.pop();
        }
        while(!temp.empty()){
            int val=temp.front();
            q.push(val);
            temp.pop();
        }
    }
    
    int pop() {
        int val=q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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