class Solution {
public:
    int singleNumber(vector<int>& v) {
        int ans=0;
        for(int val:v) ans^=val;
        return ans;
    }
};