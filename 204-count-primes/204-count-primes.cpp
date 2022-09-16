class Solution {
public:
    int countPrimes(int n) {
        long long int i=2;
        vector<int> v(n+1,1);
        int c=0;
        for(;i<n;i++){
            if(v[i]){
                c++;
                if(i>sqrt(n)) continue;
                for(int j=2*i;j<n;j+=i){
                    v[j]=0;
                }
            }
        }
        return c;
    }
};