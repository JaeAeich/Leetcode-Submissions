class Solution {
private:
    bool check(vector<vector<char>>& v, int i, int j){
        int x = (i/3)*3, y = (j/3)*3;
        for(int k = 0; k < v.size(); k++){
            if(k != i && v[k][j] == v[i][j]) return false;
        }
        for(int k = 0; k < v[0].size(); k++){
            if(k != j && v[i][k] == v[i][j]) return false;
        }
        
        for(int k = x; k < x + 3; k++){
            for(int l = y; l < y + 3; l++){
                if(k != i && l != j && v[k][l] == v[i][j]) return false;
            }
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& v) {
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                if(v[i][j] !='.' && !check(v, i, j)) return false;
            }
        }
        return true;
    }
};