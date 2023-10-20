class Solution {
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void helper(vector<vector<int>>& v, int i, int j, int c, int thisC) {
        if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] == c) {
            return;
        }
        
        if (v[i][j] == thisC) {
            v[i][j] = c;
            for (auto m : moves) {
                helper(v, i + m.first, j + m.second, c, thisC);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int thisC = image[sr][sc];
        if (thisC != newColor) {
            helper(image, sr, sc, newColor, thisC);
        }
        return image;
    }
};
