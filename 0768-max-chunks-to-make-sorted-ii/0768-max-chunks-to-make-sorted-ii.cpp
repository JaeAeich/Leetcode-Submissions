class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        vector<int> s;
        s=v;
        sort(begin(s),end(s));
        int c=0;
        
        unordered_map<int,int> f;
        unordered_map<int,int> fs;
        
        for(int i=0;i<v.size();i++){
            f[v[i]]++;
            fs[s[i]]++;
            if(f==fs) {
                c++;
                f={};
                fs={};
            }
        }
        
        return c;
    }
};