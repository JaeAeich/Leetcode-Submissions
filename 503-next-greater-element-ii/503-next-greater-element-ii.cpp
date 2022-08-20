class Solution {
public:
    //resize vector to 2*n length, perform NGE, then shrink it back.
    // loop twice
    vector<int> nextGreaterElements(vector<int>& v) {
        int n=v.size();
        //note: if we dont initialise the size here the random index access will                   give error.
        vector<int> ans(2*n);
        stack<int> s;
        // doubling size of vec by adding its ele using loop.
        for(int i=0;i<n;i++){
            v.push_back(v[i]);
        }
        //NGE on 2*n len vec.
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
        //instead of index pushing val of index.
        for(int i=0;i<n;i++){
            if(ans[i]!=-1) ans[i]=v[ans[i]];
        }
        
        //shrinking vector.
        ans.resize(n);
        v.resize(n);
        
        return ans;
    }
    
};




















