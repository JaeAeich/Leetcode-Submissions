class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(begin(v), end(v), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        int prev = 0; // Initialize to the first interval or a valid index
        int c = 0;
        for (int i = 1; i < v.size(); i++) { // Start the loop from the second interval
            if (v[i][0] < v[prev][1]) {
                c++;
                if (v[i][1] < v[prev][1]) {
                    prev = i;
                }
            } else {
                prev = i;
            }
        }
        return c;
    }
};
