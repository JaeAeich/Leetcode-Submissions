class Solution {
public:
    
    //Note: n!=(p1^x1)*(p2^x2)....
    //--> x1=floor(n/p1)+floor(n/p1^2)+floor(n/p1^3).....
    int binpow(int a,int b){
        int res=1;
        while(b){
            if(b&1) res*=a;
            a*=a;
            b>>=1;
        }
        return res;
    }
    
    int trailingZeroes(int n) {
        int c2=0,c5=0;
        int i=2;
        for(int i=1;(n/binpow(2,i));i++){
            c2+=n/binpow(2,i);
        }
        for(int i=1;(n/binpow(5,i));i++){
            c5+=n/binpow(5,i);
        }
        return min(c2,c5);
    }
};