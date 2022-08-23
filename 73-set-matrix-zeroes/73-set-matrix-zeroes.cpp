class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        vector<pair<int,int>> idx;
        int n=v.size(),m=v[0].size();
        //storing all the index that has zero.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0){
                    idx.push_back({i,j});
                }
            }
        }
        //making ele of rows and cols zero.
        for(auto p:idx){
            for(int  i=0;i<m;i++){
                v[p.first][i]=0;
            }
            for(int i=0;i<n;i++){
                v[i][p.second]=0;
            }
        }
    }
};