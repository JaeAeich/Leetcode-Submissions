class Solution {
public:
    // // brute force
    // int findKthLargest(vector<int>& v, int k) {
    //     sort(begin(v),end(v));
    //     return v[v.size()-k];
    // }
    
    // priority queue
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int> q;
        for(int i=0;i<v.size();i++){
            q.push(-v[i]);
            if(q.size()>k){
                q.pop();
            }
        }
        return -q.top();
    }
};