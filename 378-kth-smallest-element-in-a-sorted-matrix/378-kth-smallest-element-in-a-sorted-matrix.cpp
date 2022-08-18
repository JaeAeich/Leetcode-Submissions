class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        vector<int> v={};
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                v.push_back(m[i][j]);
            }
        }
        sort(begin(v),end(v));
        return v[k-1];
    }
};