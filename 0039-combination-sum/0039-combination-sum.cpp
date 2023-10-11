class Solution {
private:
    vector<vector<int>> ans;

    void helper(vector<int> &v, int t, vector<int> ans_here={}, int i=0){
        if(i>=v.size() || t<0) return;

        if(t == 0){
            ans.push_back(ans_here);
            return;
        } 

        // Take this num again
        ans_here.push_back(v[i]);
        helper(v, t-v[i], ans_here, i);
        ans_here.pop_back();

        // Don't take this num
        helper(v, t, ans_here, i+1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        sort(begin(v), end(v));    
        helper(v, t);
        return ans;
    }
};