class Solution {
public:
    //O(N)
    int kthFactor(int n, int k) {
        vector<int> v;
        v.push_back(1);
        for(int i=2;i<=n;i++){
            if(n%i==0) v.push_back(i);
        }
        return k>v.size()?-1:v[k-1];
    }
};