class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& n) {
        vector<vector<int>> ans;
        int i = 0, l = v.size();
        while(i < l && v[i][1] < n[0]){
            ans.push_back(v[i]);
            i++;
        }
        while(i < l && n[1] >= v[i][0]){
            n[0] = min(n[0], v[i][0]);
            n[1] = max(n[1], v[i][1]);
            i++;
        }
        ans.push_back(n);
        while(i < l){
            ans.push_back(v[i]);
            i++;
        }
        return ans;
    }
};