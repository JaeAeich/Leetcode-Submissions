class Solution {
public:
    //DFS to mark all image[sr][sc] with color.
    void helper(vector<vector<int>> &v,int i,int j,int col, int c){
        if(j>=v[0].size() || j<0 || i>=v.size() || i<0 ||v[i][j]==c || v[i][j]!=col) return ;
        v[i][j]=c;
        helper(v,i+1,j,col,c);
        helper(v,i-1,j,col,c);
        helper(v,i,j+1,col,c);
        helper(v,i,j-1,col,c);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        helper(image,sr,sc,image[sr][sc],color);
        return image;
    }
};