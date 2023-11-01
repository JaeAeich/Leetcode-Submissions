class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int c = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == 0){
                c++;
            }
            else v[i-c] = v[i];
        }
        for(int i = v.size() - c; i < v.size(); i++) v[i] = 0;
    }
};