class Solution {
public:
    bool isValid(vector<vector<int>> &v, int i, int j){
        return i >=0 && j>=0 && i < v.size() && j < v[0].size();
    }
    
    // Defines the moves
    vector<pair<int,int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int orangesRotting(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        
        // Stores the cordinate and the time elapsed till rotting this orange
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                // if the i, j is rotten push it in queue
                if(v[i][j] == 2){
                    q.push({{i, j},0});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            int x = cell.first.first;
            int y = cell.first.second;
            int t = cell.second;
            
            
            for(auto m : moves){
                int x1 = x+m.first;
                int y1 = y+m.second;
                
                
                // If its neighbors are fresh rot them
                if(isValid(v, x1, y1) && v[x1][y1] == 1){
                    // Rott this orange
                    v[x1][y1] = 2;
                    q.push({{x1,y1},t+1});
                    ans = max(ans, t + 1);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                if(v[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return ans;
    }
};