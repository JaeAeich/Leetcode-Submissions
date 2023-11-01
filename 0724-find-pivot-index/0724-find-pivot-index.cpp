class Solution {
public:
    int pivotIndex(vector<int>& v) {
        int tot = accumulate(begin(v), end(v), 0);
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            if(2*sum == tot - v[i]) return i;
            sum += v[i];
        }
        return -1;
    }
};