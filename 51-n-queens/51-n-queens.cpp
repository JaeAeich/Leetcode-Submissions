class Solution {
public:
    vector<vector<string>> finans={};
    
    bool isSafe(vector<string> &v,int &n, int row, int col){
        if(row<0 || col<0 || row>=n || col>=n) return false;
        for(int i=0;i<row;i++){
            if(v[i][col] =='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;--i,--j){
            if(v[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;--i,++j){
            if(v[i][j]=='Q') return false;
        }
        return true;
    }
    
    void helper(vector<string> &v, int &n, int i, int j){
        if(i>=n){
            finans.push_back(v);
            return;
        }
        if(j>=n) return;
        
        if(isSafe(v,n,i,j)){
            v[i][j]='Q';
            helper(v,n,i+1,0);
            v[i][j]='.';
            helper(v,n,i,j+1);
        }
        else{
            helper(v,n,i,j+1);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for(int i=0;i<n;i++){
            string temp;
            for(int j=0;j<n;j++){
                temp+='.';
            }
            board.push_back(temp);
        }
        helper(board,n,0,0);
        return finans;
    }
};