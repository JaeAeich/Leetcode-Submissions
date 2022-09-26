class Solution {
public:
    // TC: O(N)
    // SC: O(N)
    void rotate(vector<int>& v, int k) {
        vector<int> temp;
        int n=v.size();
        k%=n;
        for(int i=n-k;i<n;i++){
            temp.push_back(v[i]);
        }
        for(int i=0;i<n-k;i++){
            temp.push_back(v[i]);
        }
        v=temp;
    }
};