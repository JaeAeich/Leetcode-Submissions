class Solution {
public:
    double fastPow (double a, long b){
        //Initialise the ans.
        double res = 1.0;
        
        while(b){
            //if exponent is odd, multiply result with the number to make the exponent even.
            if(b&1){
                res*=a;
            }
            
            //increase the base
            a*=a;
            
            //decrease the exponent
            b=b>>1;
        }
        return res;
    }
    
    double myPow(double x, int n) {
        //base case
        if(n==0 || x==1) return 1.0;
        if(x==0) return x;
        
        if(n>0){
            return fastPow(x,n);
        }
        return fastPow(1/x,abs(n)*1LL);
    }
};