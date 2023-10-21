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

// class MedianFinder {
// private:
//     priority_queue<int> firstQ; // max_heap for the first half
//     priority_queue<int, std::vector<int>, std::greater<int> > secQ; // min_heap for the second half
// public:
//     // Adds a number into the data structure.
//     void addNum(int num) {
//         if(firstQ.empty() || (firstQ.top()>num)) firstQ.push(num); // if it belongs to the smaller half
//         else secQ.push(num); 
        
//         // rebalance the two halfs to make sure the length difference is no larger than 1
//         if(firstQ.size() > (secQ.size()+1))
//         {
//             secQ.push(firstQ.top());
//             firstQ.pop();
//         }
//         else if(firstQ.size()+1<secQ.size())
//         {
//             firstQ.push(secQ.top());
//             secQ.pop();
//         }
//     }

//     // Returns the median of current data stream
//     double findMedian() {
//         if(firstQ.size() == secQ.size()) return firstQ.empty()?0:( (firstQ.top()+secQ.top())/2.0);
//         else return (firstQ.size() > secQ.size())? firstQ.top():secQ.top(); 
//     }
// };
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */