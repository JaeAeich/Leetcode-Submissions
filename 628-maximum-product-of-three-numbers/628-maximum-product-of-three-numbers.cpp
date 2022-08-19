class Solution {
public:
    int maximumProduct(vector<int>& v) {
        // sorting
        sort(begin(v),end(v));
        auto bi=v.end();
        auto fi=v.begin();
        // aswer can either be last three ele or first two and last ele so as to make the whole product positive.
        int p1=(*(bi-1))*(*(bi-2))*(*(bi-3));
        int p2=(*(bi-1))*(*(fi))*(*(fi+1));
        
        return p1>p2?p1:p2;
    }
};