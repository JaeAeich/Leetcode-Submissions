class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        //finding nge, if exists then ans is difference between the indices of this ele and nge.
        stack<int> s;
        vector<int> ans (v.size(),0);
        for(int i=0;i<v.size();i++){
            while(!s.empty() && v[s.top()]<v[i]){
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};