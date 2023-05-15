class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        //Take the transpose of the matrix.
        for(int i=0;i<v.size();i++){
            for(int j=i;j<v.size();j++){
                swap(v[i][j],v[j][i]);
            }
        }
        //Swap the columns.
        for(int i=0;i<v.size();i++){
            int lo=0,hi=v.size()-1;
            while(lo<hi){
                swap(v[i][lo],v[i][hi]);
                lo++;
                hi--;
            }
        }
    }
};