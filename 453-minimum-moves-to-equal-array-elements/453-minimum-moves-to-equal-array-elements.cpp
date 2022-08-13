class Solution {
public:
    int minMoves(vector<int>& v) {
        //minimum element will be incremented max time.
        int min_ele=*min_element(begin(v),end(v));
        int ans=0;
        for(int n:v){
            ans+=n-min_ele;
        }
        return ans;
    }
};