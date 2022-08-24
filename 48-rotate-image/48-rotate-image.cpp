class Solution {
public:
    // Time complexity :- O(N), Space complexity:- O(1). 
    void rotate(vector<vector<int>>& v) {
        int n=v.size();
        //taking transpose w.r.t. second diagonal.
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                swap(v[i][j],v[n-j-1][n-i-1]);
            }
        }
        //Swapping the rows.
        for(int i=0;i<n/2;i++){
            swap(v[i],v[n-i-1]);
        }
    }
};