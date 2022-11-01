class Solution {
public:
    vector<int> mostCompetitive(vector<int>& v, int k) {
        int n=v.size();
        vector<int> s;
        for(int i=0;i<n;i++){
            while(s.size() && s.back()>v[i] && s.size()+n-i-1>=k){
                s.pop_back();
            }
            s.push_back(v[i]);
        }
        while(s.size()!=k){
            s.pop_back();
        }
        return s;
    }
};