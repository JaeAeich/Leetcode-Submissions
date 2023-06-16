class Solution {
public:
    vector<vector<int>> finans = {};
    
    void helper(vector<int>& v, int t, vector<int> ans={}, int i=0){
        // Base case
        if(i>=v.size() or t<0){
            if(!t) finans.push_back(ans);
            return ;
        }
        
        // Pick this ele and move
        ans.push_back(v[i]);
        helper(v,t-v[i],ans,i+1);
        ans.pop_back();
        
        // Don't pick this ele ever
        while(i+1<v.size() && v[i]==v[i+1]) i++;
        helper(v,t,ans,i+1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        // Sort the array to remove dups
        sort(begin(v),end(v));
        helper(v,t);
        return finans;
    }
};