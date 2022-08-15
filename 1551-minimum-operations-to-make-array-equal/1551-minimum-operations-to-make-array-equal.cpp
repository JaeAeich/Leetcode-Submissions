class Solution {
public:
    int minOperations(int n) {
        int k=n/2;
        int ans=n*k-(k)*(k+1)+k;
        return ans;
    }
};