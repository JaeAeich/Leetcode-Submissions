class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> hi; // min_heap
    priority_queue<int, vector<int>> lo;               // max_heap
    
public:
    MedianFinder() {}
    
    void addNum(int val) {
        if(lo.empty() || lo.top() > val) lo.push(val);
        else hi.push(val);
        
        // Balance both the halves;
        if(lo.size() >  hi.size() + 1){
            hi.push(lo.top());
            lo.pop();
        }
        else if(hi.size() > lo.size() + 1){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        if(lo.size() == hi.size()){
            return (double)(lo.top() + hi.top())/2;
        }
        return lo.size() > hi.size()? lo.top(): hi.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */