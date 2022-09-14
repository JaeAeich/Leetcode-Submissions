class Solution {
public:
    double helper(double a,long long int b){
        double res=1.0;
        while(b){
            if(b&1) {
                res*=a;
            }
            a*=a;
            b>>=1;
        }
        return res;
    }
    
    double myPow(double x, int n) {
        if(n==0 || x==1) return 1;
        if(x==0) return 0;
        if(n>0) return helper(x,n);
        return helper(1/x,abs(n)*1LL);
    }
};