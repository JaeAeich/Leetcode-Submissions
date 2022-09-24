class Solution {
public:
    vector<vector<string>> finans;
    
    //checking the if (i,j) pos is safe for the queen, by checking in both upper diagonals and upper vertical direction .
    bool pos(vector<string> &v,int i,int j){
        for(int idx=0;idx<i;idx++){
            if(v[idx][j]=='Q') return false;
        }
        for(int idx=i-1,jdx=j+1;idx>=0 && jdx<v.size();idx--,jdx++){
            if(v[idx][jdx]=='Q') return false;
        }
        for(int idx=i-1,jdx=j-1;idx>=0 && jdx>=0;idx--,jdx--){
            if(v[idx][jdx]=='Q') return false;
        }
        return true;
    }
    
    //dfs
    void helper(vector<string> &v,int idx=0){
        if(idx>=v.size()){
            finans.push_back(v);
            return;
        }
        for(int i=0;i<v.size();i++){
            if(!pos(v,idx,i)) continue;
            v[idx][i]='Q';
            helper(v,idx+1);
            v[idx][i]='.';
        }
    }
    //driver code
    vector<vector<string>> solveNQueens(int n) {
        vector<string> b(n,string(n,'.'));
        helper(b);
        return finans;
    }
};