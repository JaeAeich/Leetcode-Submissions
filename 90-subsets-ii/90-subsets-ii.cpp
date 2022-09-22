class Solution {
public:
    vector<vector<int>> finans={};
    
    void helper(vector<int> &v,int i=0,vector<int> ans={}){
        if(i==v.size()){
            sort(begin(ans),end(ans));
            finans.push_back(ans);
            return;
        }
        ans.push_back(v[i]);
        helper(v,i+1,ans);
        while(i+1<v.size() && v[i]==v[i+1]) i+=1;
        ans.pop_back();
        helper(v,i+1,ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(nums);
        return finans;
    }
};