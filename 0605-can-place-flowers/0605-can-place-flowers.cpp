class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int c = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == 0){
                bool leftIsEmpty = (i == 0) || (v[i - 1] == 0);
                bool rightIsEmpty = (i == v.size() - 1) || (v[i + 1] == 0);
                
                if(leftIsEmpty && rightIsEmpty){
                    c++;
                    v[i] = 1;
                }
            }
        }
        return c >= n;
    }
};