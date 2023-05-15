class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(begin(v),end(v),cmp);
        vector<vector<int>> ans={};
        int s=v[0][0];
        int e=v[0][1];
        for(int i=0;i<v.size();i++){
            if(v[i][0]<=e){
                if(v[i][1]>e) e=v[i][1];
            }
            else{
                ans.push_back({s,e});
                s=v[i][0];
                e=v[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};