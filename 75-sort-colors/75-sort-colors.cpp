class Solution {
public:
    // Selection sort O(N^2).
    void sortColors(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                //swap the greater element with the smallest one.
                if(v[j]<v[i]){
                    v[i]^=v[j];
                    v[j]^=v[i];
                    v[i]^=v[j];
                }
            }
        }
    }
};