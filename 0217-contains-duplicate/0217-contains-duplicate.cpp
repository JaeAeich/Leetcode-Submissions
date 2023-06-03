class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        // create a hash set for freq
        map<int,int> m;
        for(int val: v){
            m[val]++;
            // If freq is greater than 1 that means this is the repeating int
            if(m[val]>1) return true;
        }
        return false;
    }
};