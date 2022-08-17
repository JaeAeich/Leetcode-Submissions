class Solution {
public:
    int uniquePaths(int m, int n) {
        m--; // total down steps.
        n--; // total right steps.
        
        //total ways to arrange a string of m downs and n rights.
        int val=m+n;
        if(m<n){
            m=m^n;
            n=n^m;
            m=m^n;
        }
        long long int ans=1;
        int j=1;
        // finding (m+n)!/n!*m!
        for(int i=m+1;i<=m+n || j<=n;i++){
            ans*=i;
            if(j<=n) ans/=j;
            j++;
        }
        return ans;
    }
};