class Solution {
public:
    void sortColors(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(v[j]<v[i]){
                    swap(v[j],v[i]);
                }
            }
        }
    }
};