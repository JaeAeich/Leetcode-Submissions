class Solution {
public:
    //Dfs making all the '1' --> '0' of the grid.
    void dfs(vector<vector<char>>& v,int i=0,int j=0){
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size()|| v[i][j]=='0') return;
        v[i][j]='0';
        dfs(v,i+1,j);
        dfs(v,i,j+1);
        dfs(v,i,j-1);
        dfs(v,i-1,j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //for each '1' flood filling the grid.
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    //number of time, flood fill is possible is the number of islands.
                    c++;
                }
            }
        }
        return c;
    }
};