class Solution {
public:
    // //O(N^2)
    // vector<int> canSeePersonsCount(vector<int>& v) {
    //     vector<int> ans(v.size());
    //     ans.back()=0;
    //     for(int i=0;i<v.size();i++){
    //         for(int j=i+1;j<v.size();j++){
    //             int maxH=INT_MIN;
    //             for(int k=i+1;k<=j-1;k++){
    //                 maxH=max(maxH,v[k]);
    //             }
    //             int minH=min(v[i],v[j]);
    //             if(minH>maxH) ans[i]++;
    //         }
    //     }
    //     return ans;
    // }
    
    vector<int> canSeePersonsCount(vector<int>& v){
        stack<int> s;
        vector<int> ans(v.size());
        for(int i=0;i<v.size();i++){
            //if ith person is bigger than stack top then stack top can see ith person.
            //so we will increase the count stack top.
            while(!s.empty() && v[i]>=v[s.top()]){
                ans[s.top()]+=1;
                s.pop();
            }
            //if stack has some people left then that person is taller than ith guy.
            //since hecan see ith person so we will increase its count too.
            //note: the guy behind him on stack cant see him, as stack top is blocking the view.
            if(s.size()) ans[s.top()]+=1;
            s.push(i);
        }
        return ans;
    }
};












