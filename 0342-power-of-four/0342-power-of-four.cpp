class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <=0 ) return false;
        
        // Need to be a power of 2
        if(n&(n-1)) return false;
        
        // Set bit needs to be at odd position
        return n&0x555555555;
    }
};