class Solution {
public:
    // Assume only accepts pos n and x
    double fastPow(double x, long long int  n){
        double res = 1;
        while(n){
            if(n&1){
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
    
    
    double myPow(double x, long long int n) {
        // Obvious case 
        if(x == 1 or n == 0) return 1;
        
        if(n < 0) x = 1/x;
        
        // if(n==INT_MIN)
        n = abs(n);
        
        if(x<0){
            x = abs(x);
            if(n%2) return -fastPow(x,n);
            return fastPow(x,n);
        }
        
        return fastPow(x,n);
    }
};