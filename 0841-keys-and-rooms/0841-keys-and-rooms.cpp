class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& v) {
        unordered_map<int,bool> vis;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int key = q.front();
            q.pop();
            if(vis[key]) continue;
            vis[key] = true;
            for(int i = 0; i < v[key].size(); i++){
                q.push(v[key][i]);
            }
        }
        for(int i = 0; i < v.size(); i++){
            if(vis.find(i) == vis.end()) return false;
        }
        return true;
    }
};