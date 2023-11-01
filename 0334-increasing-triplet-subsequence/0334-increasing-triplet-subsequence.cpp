class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        int lo = INT_MAX;
        int hi = INT_MAX;
        for(int i = 0; i < v.size(); i++){
            if(v[i] <= lo) lo = v[i];
            else if(v[i] < hi) hi = v[i];
            else if(v[i] > hi) return true;
        }
        return false;
    }
};