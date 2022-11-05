class Solution {
public:
    // //Brute force,O(N^3)
    // long long subArrayRanges(vector<int>& v) {
    //     long long int ans=0;
    //     for(int i=0;i<v.size();i++){
    //         for(int k=i;k<v.size();k++){
    //             long long int minn=INT_MAX;
    //             long long int maxx=INT_MIN;
    //             for(int j=i;j<=k;j++){
    //                 minn=[](int a,int b){return a>b?b:a;}(minn,v[j]);
    //                 maxx=[](int a,int b){return a>b?a:b;}(maxx,v[j]);
    //             }
    //             ans+=maxx-minn;
    //         }
    //     }
    //     return ans;
    // }
    
    //brute force O(N^2)
    long long subArrayRanges(vector<int>& v) {
        int n=v.size();
        long long int ans=0;
        for(int i=0;i<n;++i){
            int minn=v[i],maxx=v[i];
            for(int j=i;j<n;++j){
                maxx=max(maxx,v[j]);
                minn=min(minn,v[j]);
                ans+=maxx-minn;
            }
        }
        return ans;
    }
    
};