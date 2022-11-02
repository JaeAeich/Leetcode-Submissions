class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        // making a sorted vector to compare the unsorte vec to.
        vector<int> s;
        s=v;
        sort(begin(s),end(s));
        int c=0;
        //frequency hash map for sorted and unsorted vec.
        unordered_map<int,int> f;
        unordered_map<int,int> fs;
        
        for(int i=0;i<v.size();i++){
            //keeping tab of freq of ele of sorted and unsorted vec.
            f[v[i]]++;
            fs[s[i]]++;
            //if at any point the freq becomes equal , that means it containts a chunk.
            if(f==fs) {
                c++;
            }
        }
        
        return c;
    }
};