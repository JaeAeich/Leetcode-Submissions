class Solution {
public:
    // // brute force O(n^2) (TLE)
    // vector<int> dailyTemperatures(vector<int>& v) {
    //     vector<int> ans={};
    //     int n=v.size();
    //     for(int i=0;i<n-1;i++){
    //         int j=i+1;
    //         while(j<n && v[i]>=v[j]) j++;
    //         ans.push_back(j==n?0:j-i);
    //     }
    //     ans.push_back(0);
    //     return ans;
    // }
    
    //NGE algorithm O(n)
    vector<int> dailyTemperatures(vector<int>& v) {
        // keeping a stack of indexes.
        stack<int> s;
        vector<int> ans(v.size());
        for(int i=0;i<v.size();i++){
            // if that stack isn't empty.
            // And the ele in loop is greater than ele of index on top of stack.
            while(!s.empty() && v[i]>v[s.top()]){
                // push distance form i to s.top.
                ans[s.top()]=-s.top()+i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty()){
            ans[s.top()]=0;
            s.pop();
        }
        
        return ans;
    }
};