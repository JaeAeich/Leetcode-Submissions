class Solution {
public:
    // //Time complexity:-O(mn), Space complexity :- O(m+n).
    // void setZeroes(vector<vector<int>>& v) {
    //     vector<pair<int,int>> idx;
    //     int n=v.size(),m=v[0].size();
    //     //storing all the index that has zero.
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(v[i][j]==0){
    //                 idx.push_back({i,j});
    //             }
    //         }
    //     }
    //     //making ele of rows and cols zero.
    //     for(auto p:idx){
    //         for(int  i=0;i<m;i++){
    //             v[p.first][i]=0;
    //         }
    //         for(int i=0;i<n;i++){
    //             v[i][p.second]=0;
    //         }
    //     }
    // }
    
    //Time complexity:- O(mn) , Space complexity:- O(1).
    void setZeroes(vector<vector<int>>& v) {
        bool col=false,row=false;
        int n=v.size(),m=v[0].size();
        for(int i=0;i<m;i++){
            if(v[0][i]==0){
                row=true;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(v[i][0]==0){
                col=true;
                break;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(v[i][j]==0){
                    v[i][0]=v[0][j]=0;
                }
            }
        }
        for(int j=1;j<m;j++){
            if(v[0][j]==0){
                for(int k=1;k<n;k++){
                    v[k][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(v[i][0]==0){
                for(int k=1;k<m;k++){
                    v[i][k]=0;
                }
            }
        }
        if(col){
            for(int i=0;i<n;i++){
                v[i][0]=0;
            }
        }
        if(row){
            for(int i=0;i<m;i++){
                v[0][i]=0;
            }
        }
    }
};
































