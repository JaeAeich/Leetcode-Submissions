class Solution {
public:
    vector<vector<int>> finans = {};
    
    void helper(vector<int> &v, int t, int idx=0,vector<int> ans={}){
        if(t<0 || idx>v.size()) return;
        if(t==0){
            finans.push_back(ans);
            return ;
        }
        
        for(int i=idx;i<v.size();++i){
            if(t-v[i]<0) return;
            ans.push_back(v[i]);
            helper(v,t-v[i],i+1,ans);
            while(i+1<v.size() && v[i]==v[i+1]) i++;
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        // Sort the array to remove dups
        sort(begin(v),end(v));
        helper(v,t);
        return finans;
    }
};