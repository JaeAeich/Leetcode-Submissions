class Solution {
public:
    // //brute force
    // int kthSmallest(vector<vector<int>>& m, int k) {
    //     vector<int> v={};
    //     for(int i=0;i<m.size();i++){
    //         for(int j=0;j<m[0].size();j++){
    //             v.push_back(m[i][j]);
    //         }
    //     }
    //     sort(begin(v),end(v));
    //     return v[k-1];
    // }
    
    // priority queue
    int kthSmallest(vector<vector<int>>& v, int k){
        priority_queue<int> p;
        int n=v.size(),m=v[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                p.push(v[i][j]);
                if(p.size()>k) p.pop();
            }
        }
        return p.top();
    }
};