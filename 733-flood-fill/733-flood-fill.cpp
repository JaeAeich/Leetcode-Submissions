class Solution {
public:
    //DFS to mark all image[sr][sc] with color.
    void helper(vector<vector<int>> &v,vector<vector<bool>> vis,int i,int j,int col, int c){
        if(j>=v[0].size() || j<0 || i>=v.size() || i<0 ||vis[i][j]==1) return ;
        if(v[i][j]==c || v[i][j]!=col) return;
        vis[i][j]=1;
        v[i][j]=c;
        helper(v,vis,i+1,j,col,c);
        helper(v,vis,i-1,j,col,c);
        helper(v,vis,i,j+1,col,c);
        helper(v,vis,i,j-1,col,c);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //visited array to keep track.
        vector<vector<bool>> vis(image.size(),vector<bool>(image[0].size(),0));
        helper(image,vis,sr,sc,image[sr][sc],color);
        return image;
    }
};