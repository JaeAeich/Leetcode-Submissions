class Solution {
private:
    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
public:
    int orangesRotting(vector<vector<int>>& v) {
        // Get the size of grid
        int n = v.size(), m = v[0].size();
        // Queue for BFS
        queue<vector<int>> q;
        // Max time taken to rott oranges
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == 2){
                    // Get the starting points for BFS
                    v[i][j] = 1;
                    q.push({i, j, 0});
                }
            }
        }
        while(!q.empty()){
            auto vec = q.front();
            q.pop();
            int i = vec[0], j = vec[1], t = vec[2];
            // check if this is a valid orange 
            if(i < 0 || j < 0 || i >= n || j >= m || v[i][j] == 0 || v[i][j] == 2) continue;
            
            // Rott this orange
            v[i][j] = 2;
            
            // Update the ans
            ans = max(ans, t);
            for(auto m : moves){
                // Rott its neighbour
                q.push({i + m.first, j  +m.second, t + 1});
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return ans;
    }
};