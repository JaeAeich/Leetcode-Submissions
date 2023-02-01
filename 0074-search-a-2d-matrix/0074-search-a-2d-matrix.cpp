class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n=v.size(),m=v[0].size();
        //start itterating from the top right corner.
        for(int i=0,j=m-1;i<n && j>=0;){
            //if ele found return true.
            if(v[i][j]==t) return true;
            //if ele is greater move to search space of smaller ele.
            else if(v[i][j]>t){
                j--;
            }
            //move to search space of larger ele.
            else i++;
        }
        return false;
    }
};