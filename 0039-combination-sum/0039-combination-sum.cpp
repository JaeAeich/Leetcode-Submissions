class Solution {
public:
    vector<vector<int>> finans = {};
    
    void helper(vector<int>& v, int t, vector<int> ans = {}, int i=0){
        if(i>=v.size() or t<=0){
            if(!t) finans.push_back(ans);
            return ;
        }
        // Pick the ith ele and possibly again pick it
        ans.push_back(v[i]);
        helper(v,t-v[i],ans,i);
        
        // Don't pick this ele and move on
        ans.pop_back();
        helper(v,t,ans,i+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        sort(begin(v),end(v));
        helper(v,t);
        return finans;
    }
};