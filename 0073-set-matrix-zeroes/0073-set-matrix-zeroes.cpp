class Solution {
public:
//     //SC = O(mn), TC : O(mn)
//     void setZeroes(vector<vector<int>>& v) {
//         vector<pair<int,int>> zero;
//         for(int i=0;i<v.size();i++){
//             for(int j=0;j<v[0].size();j++){
//                 if(v[i][j]==0) zero.push_back({i,j});
//             }
//         }
//         for(auto p : zero){
//             int row = p.first;
//             int col = p.second;
            
//             for(int i = 0;i<v.size();i++){
//                 v[i][col]=0;
//             }
            
//             for(int i=0;i<v[0].size();i++){
//                 v[row][i]=0;
//             }
//         }
//     }
    
    void setZeroes(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        //if there is 0 in the first row.
        bool fr = false;
        
        //if any element in the first row is zero.
        for(int i=0;i<n;i++){
            if(v[i][0]==0) fr = true;
        }
        
        //if (i,j) entry is 0, make v[i][0] and v[0][j] as 0, except for the special case of 1st row.
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(v[i][j]==0){
                    v[0][j]=0;
                    v[i][0]=0;
                }
            }
        }
        
        //Iterate in the 1st row and if 0 foun make that col zero.
        for(int i=1;i<n;i++){
            if(v[i][0]==0){
                for(int j=1;j<m;j++){
                    v[i][j]=0;
                }
            }
        }
        //Do the same for col
        for(int j=1;j<m;j++){
            if(v[0][j]==0){
                for(int i=1;i<n;i++){
                    v[i][j]=0;
                }
            }
        }
        
        //if v[0][0] is 0, make the 1st col zero and if fr is true make first row zero.
        if(!v[0][0]){
            for(int j=0;j<m;j++){
                v[0][j]=0;
            }
        }
        
        if(fr){
            for(int i=0;i<n;i++){
                v[i][0]=0;
            }
        }
        cout<<fr;
    }
    
};