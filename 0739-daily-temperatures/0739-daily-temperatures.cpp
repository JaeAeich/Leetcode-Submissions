class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        //finding nge
        stack<int> s;
        vector<int> nge (v.size(),-1);
        for(int i=0;i<v.size();i++){
            while(!s.empty() && v[s.top()]<v[i]){
                nge[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        //checking when the nge comes after this ele.
        vector<int> ans(v.size());
        for(int i=0;i<v.size();i++){
            if(nge[i]!=-1){
                ans[i]=nge[i]-i;
            }
            //if this ele doesnt have nge then ans[i]=0 (according to ques).
            else{
                ans[i]=0;
            }
        }
        return ans;
    }
};