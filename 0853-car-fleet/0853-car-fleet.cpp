class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        vector<pair<int,int>> v;
        for(int i=0;i<p.size();i++){
            v.push_back(make_pair(p[i],s[i]));
        }
        sort(begin(v),end(v));
        stack<float> st;
        for(int i=v.size()-1;i>=0;i--){
            float time=((1.0*(t-v[i].first))/v[i].second);
            // cout<<t-v[i].first<<" "<<v[i].second<<" "<<time<<endl;
            if(st.empty() || st.top()<time){
                st.push(time);
            }
        }
        return st.size();
    }
};