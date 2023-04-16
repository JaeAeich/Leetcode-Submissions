class Solution {
public:
    vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool DFS(vector<vector<char>>& v, string &w,vector<vector<bool>> &vis,int i, int j,string s=""){
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || vis[i][j] || v[i][j]!=w[s.size()]) return false;
        
        s += v[i][j];
        if(s == w) return true;
        
        vis[i][j] = true;
        for(auto p : moves){
            int i1=i+p.first;
            int j1=j+p.second;
            if(DFS(v, w, vis, i1, j1, s)) return true;
        }
        
        vis[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m));
        vector<pair<int,int>> start_point={};
        //get all the start points from where to do DFS
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    start_point.push_back({i,j});
                }
            }
        }
        
        bool ans = false;
        
        for(auto p : start_point){
            ans |=DFS(board,word,vis,p.first,p.second);
        }
        
        return ans;
        
    }
};