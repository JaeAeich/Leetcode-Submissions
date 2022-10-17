class Solution {
public:
    bool search(vector<int>& v, int t) {
        for(int val:v){
            if(val==t) return true;
        }
        return false;
    }
};