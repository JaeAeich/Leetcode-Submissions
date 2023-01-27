class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n=v.size();
        //creating a prefix product array
        vector<int> p(n,1);
        //creating a suffix product array
        vector<int> s(n,1);
        int prev_p=1,prev_s=1;
        for(int i=1,j=n-2;i<v.size();i++,j--){
            //creating a prefix prod array.
            p[i]=prev_p*v[i-1];
            prev_p=p[i];
            //creating a suffix prod array.
            s[j]=prev_s*v[j+1];
            prev_s=s[j];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=s[i]*p[i];
        }
        return ans;
    }
};