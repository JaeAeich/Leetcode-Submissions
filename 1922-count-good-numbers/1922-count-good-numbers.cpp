class Solution {
public:
    typedef long long int ll;
    int m=1e9+7;
    ll binPow(ll a,ll b){
        if(b==0) return 1;
        if(b&1){
            return ((a*1LL*binPow(a,b-1))%m);
        }
        a=(a*1LL*a)%m;
        return (binPow(a,b/2)%m);
    }
    int countGoodNumbers(long long n) {
        return (binPow(5,(n+1)/2)*1LL*binPow(4,n/2))%m;
    }
};