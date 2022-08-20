class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n=v.size();
        vector<int> ans(2*n);
        stack<int> s;
        for(int i=0;i<n;i++){
            v.push_back(v[i]);
        }
        for(int i=0;i<2*n;i++){
            while(!s.empty() && v[i]>v[s.top()]){
                ans[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            ans[s.top()]=-1;
            s.pop();
        }
        
        for(int i=0;i<n;i++){
            if(ans[i]!=-1) ans[i]=v[ans[i]];
        }
        ans.resize(n);
        return ans;
    }
};