class Solution {
public:
    vector<vector<int>> finans;
    
    void helper(vector<int>& v, int k, int i=0,vector<int> ans={},int sum=0){
        if(i>v.size() || sum>k) return;
        if(i==v.size()){
            if(sum==k) finans.push_back(ans);
            return ;
        }
        sum+=v[i];
        ans.push_back(v[i]);
        helper(v,k,i,ans,sum);
        sum-=v[i];
        ans.pop_back();
        helper(v,k,i+1,ans,sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates,target);
        return finans;
    }
};