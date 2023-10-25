class Solution {
private:
    int helper(vector<int> &v, int i, int j){
        int res = INT_MIN;
        int p = 1;
        for(int k = i; k <= j; k++){
            p *= v[k];
            res = max(res, p);
        }
        p = 1;
        for(int k = j; k >= i; k--){
            p *= v[k];
            res = max(res, p);
        }
        return res;
    }
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        vector<int> idx0;
        int ans = *max_element(begin(v), end(v));
        for(int i = 0; i < n; i++){
            if(v[i] == 0) idx0.push_back(i);
        }
        idx0.push_back(n);
        int lo = -1;
        for(int i = 0; i < idx0.size(); i++){
            ans = max(ans, helper(v, lo + 1, idx0[i] -1));
            lo = idx0[i];
        }
        return ans;
    }
};