class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n=v.size(),m=v[0].size();
        int i=0,j=m-1;
        //Starting form the top right corner.
        //If ever reached out of bound return false.
        while(i<n && j>=0){
            // If ele found return true.
            if(v[i][j]==t){
                return true;
            }
            //If this ele is larger than target, go to prev ele in matrix.
            else if(v[i][j]>t) j--;
            //Else go down in matrix.
            else i++;
        }
        return false;
    }
};