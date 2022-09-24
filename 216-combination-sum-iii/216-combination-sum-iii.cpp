class Solution {
public:
    vector<vector<int>> finans;
    
    void helper(int k, int n,vector<int> vis,int i=1,int sum=0,vector<int> ans={}){
        if(sum>k || ans.size()>n) return ;
        if(sum==k && ans.size()==n){
            finans.push_back(ans);
            return;
        }
        if(i>=vis.size()) return;
        
        if(vis[i]){
            vis[i]=0;
            ans.push_back(i);
            helper(k,n,vis,i+1,sum+i,ans);
            vis[i]=1;
            ans.pop_back();
        }
        
        helper(k,n,vis,i+1,sum,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vis(10,1);
        helper(n,k,vis);
        return finans;
    }
};