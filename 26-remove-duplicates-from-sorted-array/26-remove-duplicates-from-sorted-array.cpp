class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        //vouter to keep cout of dup ele.
        int c=0;
        for(int i=1;i<v.size();i++){
            if(v[i-1]==v[i]) c++;
            //If ith ele isnt dup then shift it back.
            else v[i-c]=v[i];
        }
        return v.size()-c;
    }
};