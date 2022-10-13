class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
        stack<int> s;
        vector<int> nge(v2.size(),-1);
        //forming nge vector for v2.
        for(int i=0;i<v2.size();i++){
            if(s.empty() || v2[s.top()]>v2[i]){
                s.push(i);
            }
            else{
                while(!s.empty() && v2[s.top()]<v2[i]){
                    nge[s.top()]=v2[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        for(int i=0;i<v1.size();i++){
            int idx=find(begin(v2),end(v2),v1[i])-begin(v2);
            v1[i]=nge[idx];
        }
        return v1;
    }
};