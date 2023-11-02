class Solution {
private:
    void dfs(vector<vector<int>> &v, int i, vector<bool> &vis){
        if(vis[i]) return;
        vis[i] = true;
        for(int k = 0; k < v[i].size(); k++){
            if(v[i][k] && i != k) dfs(v, k, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& v) {
        int ans = 0, n = v.size();
        vector<bool> vis(n);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(v, i, vis);
                ans++;
            }
        }
        return ans;
    }
};