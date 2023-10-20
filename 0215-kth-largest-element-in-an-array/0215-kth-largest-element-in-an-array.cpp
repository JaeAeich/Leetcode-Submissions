class Solution {
private:
    int part(vector<int>& v, int i, int j){
        int piv = i;
        int lo = i + 1;
        int hi = j;
        while (lo <= hi) {
            if (v[lo] > v[piv] && v[hi] < v[piv]) {
                swap(v[lo], v[hi]);
            }
            if (v[lo] <= v[piv]) lo++;
            if (v[hi] >= v[piv]) hi--;
        }
        swap(v[hi], v[piv]);
        return hi;
    }
public:
    int findKthLargest(vector<int>& v, int k) {
        int n = v.size();
        int lo = 0, hi = n - 1;
        k = n - k;
        int ans = -1;
        while(true){
            int idx = part(v, lo, hi);
            if(k == idx){
                ans = v[idx];
                break;
            }
            else if(k > idx) lo = idx + 1;
            else hi = idx - 1;
        }
        return ans;
    }
};