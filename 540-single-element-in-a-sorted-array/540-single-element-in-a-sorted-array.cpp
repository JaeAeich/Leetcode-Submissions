class Solution {
public:
    //Using xor property
    int singleNonDuplicate(vector<int>& v) {
        int ans=0;
        for(int val:v){
            ans^=val;
        }
        return ans;
    }
};