class Solution {
public:
    double dist(vector<int> &v){
        int a=v[0],b=v[1];
        a*=a;
        b*=b;
        double ans=(double)sqrt(a+b);
        return ans;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {
        multimap<double,vector<int>> m;
        vector<vector<int>> ans={};
        for(vector<int> vec: v){
            double d=dist(vec);
            m.insert({d,vec});
        }
        auto it=m.begin();
        for(int i=0;i<k;i++){
            vector<int> vect=it->second;
            ans.push_back(vect);
            it++;
        }
        return ans;
    }
};