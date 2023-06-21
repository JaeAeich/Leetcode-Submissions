class Solution {
private:
    vector<vector<string>> finans = {};
    
    // Checks if i, j  is a safe position for a queen
    bool isValid(vector<string>& board, int n, int i, int j) {
        // Check if any queen is atttacking i, j
        static const vector<pair<int, int>> directions = {
            {-1, 1}, {-1, -1}
        };

        // Check vertical directions as invalid
        for (int k = 0; k < n; k++) {
            if(board[k][j]=='Q') return false;
        }


        // Check cross directions
        for (const auto& dir : directions) {
            int x = i;
            int y = j;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                if(board[x][y] == 'Q') return false;
                x += dir.first;
                y += dir.second;
            }
        }
        return true;
    }

    // Generate the possibilities
    void helper(vector<string> &board, int n, int i=0){
        // If the borad is exhauseted store that board
        if(i >= n) {
            finans.push_back(board);
            return;
        }
        
        for(int j = 0; j < n; j++){
            // If i, j is a valid position for queen
            if(isValid(board, n, i, j)){
                // Put the queen at i, j
                board[i][j]='Q';
                helper(board, n, i+1);
                
                // Backtrack
                board[i][j]='.';
            }
        }
    }
public:
    
    // Driver code
    vector<vector<string>> solveNQueens(int n) {
        // Create an empty board
        vector<string> board (n, string(n, '.'));
        helper(board,n);
        return finans;
    }
};