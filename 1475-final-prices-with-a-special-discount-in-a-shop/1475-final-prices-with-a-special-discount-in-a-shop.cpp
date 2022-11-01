class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        stack<int> s;
        vector<int> nse(v.size(),-1);
        //finding all the next smaller ele index, if it doesnt exist then storing -1.
        for(int i=0;i<v.size();i++){
            while(!s.empty() && v[s.top()]>=v[i]){
                nse[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            if(nse[i]!=-1){
                ans.push_back(v[i]-v[nse[i]]);
            }
            else ans.push_back(v[i]);
        }
        return ans;
    }
};