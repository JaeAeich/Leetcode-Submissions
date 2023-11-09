class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        sort(begin(v), end(v), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int n = v.size();
        if(n <= 1) return n;
        vector<int> ans;
        ans.push_back(v[0][1]);
        for(int i = 1; i < n; i++){
            if(v[i][1] > ans.back()) ans.push_back(v[i][1]);
            else{
                int idx = lower_bound(begin(ans), end(ans), v[i][1]) - begin(ans);
                ans[idx] = v[i][1];
            }
        }
        return ans.size();
    }
};