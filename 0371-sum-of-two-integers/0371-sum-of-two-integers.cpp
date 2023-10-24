class Solution {
public:
    int getSum(int a, int b) {
        if(b ==0) return a;
        
        int carry = a&b;
        
        // Add the numbers ignoring carry
        int add = a^b;
        
        // Shift the carry
        carry = carry<<1;
        
        return getSum(add, carry);
    }
};