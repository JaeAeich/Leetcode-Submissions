class Solution {
public:
    // brute force
    int findKthLargest(vector<int>& v, int k) {
        sort(begin(v),end(v));
        return v[v.size()-k];
    }
};