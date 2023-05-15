class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        //sort intervals wrt starting time.
        sort(begin(v),end(v),[](vector<int> &a, vector<int> &b) {return a[0]<b[0];});
        //Push the first interval as it will be in the ans and update it if needed.
        vector<vector<int>> ans = {v[0]};
        
        //Iterate though the intervals and check is this interval overlaps with the prev.
        for(int i=1;i<v.size();i++){
            int s = v[i][0];
            int e = v[i][1];
            //if overlaps.
            if(ans.back()[1]>=s){
                if(e>ans.back()[1]){
                    ans.back()[1]=e;
                }
            }
            //else push a new interval.
            else{
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};