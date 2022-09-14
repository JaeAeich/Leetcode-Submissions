class Solution {
public:
    //Using ETF, phi(1337)=1140--->phi(1337)=1337*(1-1/6)*(1-1/190)
    //Using Eulers theorem we can say, (a^b)%m=(a^(b%phi(m)))%m.
    int m=1140;
    int mod=1337;
    
    int binpow(int a,int b){
        int res=1;
        while(b){
            if(b&1){
                res=(res*1LL*a)%mod;
            }
            a=(a*1LL*a)%mod;
            b>>=1;
        }
        return res;
    }
    int superPow(int a, vector<int>& v) {
        if(a==0) return 0;
        if(a==1) return 1;
        int n=v.size();
        int e=0,prev=1;
        //calculating the exponent modulo phi(1337)
        for(int i=n-1;i>=0;i--){
            e+=(v[i]*1LL*(prev%m))%m;
            prev=(prev*1LL*10)%m;
        }
        if(e==0) return 1;
        //calculating power
        return binpow(a,e);
    }
};