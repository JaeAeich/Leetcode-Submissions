class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        //if n is power of 2 then n-1 will have all bit set previous to set bit of n;
        return !(n&(n-1));
    }
};