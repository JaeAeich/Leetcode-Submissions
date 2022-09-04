class Solution {
public:
    //O(N) solution, simple iterartion(for loop).
    int findKthPositive(vector<int>& v, int k) {
        int c=0;
        for(int i=1,j=0;;i++){
            if(j<v.size() && i==v[j]){
                j++;
            }
            else{
                 c++;
            }
            
            if(c==k){
                return i;
            }
        }
    }
};