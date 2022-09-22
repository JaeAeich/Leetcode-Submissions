class Solution {
public:
    vector<vector<int>> finans={};
    
    void helper(vector<int> &v,int i=0,vector<int> ans={}){
        if(i==v.size()){
            sort(begin(ans),end(ans));
            if(find(begin(finans),end(finans),ans)==finans.end()){
                finans.push_back(ans);
            }
            return;
        }
        ans.push_back(v[i]);
        helper(v,i+1,ans);
        ans.pop_back();
        helper(v,i+1,ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        helper(nums);
        return finans;
    }
};