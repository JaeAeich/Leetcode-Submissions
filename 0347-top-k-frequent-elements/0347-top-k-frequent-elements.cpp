class Solution {
public:
    //brute force
    vector<int> topKFrequent(vector<int>& v, int k) {
        map<int,int> m;
        vector<pair<int,int>> vp;
        for(int val:v){
            m[val]++;
        }
        for(auto it =begin(m);it!=end(m);it++){
            vp.push_back({it->second,it->first});
        }
        sort(begin(vp),end(vp));
        vector<int> ans;
        int i=vp.size()-1;
        for(auto p:vp ){
            if(!(k--)) break;
            ans.push_back(vp[i--].second);
        }
        return ans;
    }
};