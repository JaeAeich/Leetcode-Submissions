class Solution {
private:
    vector<vector<int>> ans;

    void helper(vector<int> v, int t, vector<int> ans_here = {}, int i=0){
        if(t == 0){
            ans.push_back(ans_here);
            return;
        }

        if(i >= v.size() || t < 0) return;

        // Take this ele
        ans_here.push_back(v[i]);
        helper(v, t - v[i], ans_here, i+1);
        ans_here.pop_back();

        // Don't take this ele and skip all its occurances
        int j = i + 1;
        while(j < v.size() && v[i] == v[j]) j++;
        helper(v, t, ans_here, j);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        sort(begin(v), end(v));
        helper(v, t);
        return ans;
    }
};