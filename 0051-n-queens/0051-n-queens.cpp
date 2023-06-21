class Solution {
private:
    vector<vector<string>> finans = {};
    
    // Mark all the moves that aren't valid after placing queen at i, j
    void markNotPossiblePaths(vector<vector<bool>>& valid, int n, int i, int j) {
        // all the possible directions of attack
        static const vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };

        // Mark vertical and horizontal directions as invalid
        for (int k = 0; k < n; k++) {
            valid[i][k] = false;
            valid[k][j] = false;
        }


        // Mark all the cross directions
        for (const auto& dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                valid[x][y] = false;
                x += dir.first;
                y += dir.second;
            }
        }
    }

    // Generate the possibilities
    void helper(vector<string> &board, vector<vector<bool>> &valid, int n, int i=0){
        // If the borad is exhauseted store that board
        if(i >= board.size()) {
            finans.push_back(board);
            return;
        }
        
        for(int j = 0; j < n; j++){
            // If i, j is a valid position for queen
            if(valid[i][j]){
                // Put the queen at i, j
                board[i][j]='Q';
                vector<vector<bool>> temp = valid;
                
                // Mark all the places queen can;t be kept due to this queen
                markNotPossiblePaths(valid, n, i, j);
                helper(board, valid, n, i+1);
                
                // Backtrack
                valid = temp;
                board[i][j]='.';
            }
        }
    }
public:
    
    // Driver code
    vector<vector<string>> solveNQueens(int n) {
        // Valid vector, tells if queen at i,j is possible or not
        vector<vector<bool>> valid(n,vector<bool>(n,1));
        
        // Create a board
        vector<string> board;
        for(int i = 0; i < n; i++){
            string temp = "";
            for(int i = 0; i < n; i++){
                temp +='.';
            }
            board.push_back(temp);
        }
        
        // Generate all the possible boards and return
        helper(board, valid, n);
        return finans;
    }
};