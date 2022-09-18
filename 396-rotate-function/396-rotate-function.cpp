class Solution {
public:
    //From observation we get, f(k)-f(k-1)=sum-n*(v[n-k]).
    int maxRotateFunction(vector<int>& v) {
        int n=v.size();
        int sum=accumulate(begin(v),end(v),0);
        vector<int> ans(n);
        ans[0]=0;
        for(int i=0;i<n;i++){
            ans[0]+=v[i]*i;
        }
        for(int i=1;i<n;i++){
            ans[i]=sum+ans[i-1]-(n*v[n-i]);
        }
        return *max_element(begin(ans),end(ans));
    }
};