class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> finans;
        //sorting to use three pointer technique.
        sort(begin(v),end(v));
        int n=v.size();
        for(int i=0;i<n-2;i++){
            //If ith ele is same as prev countinue.
            if(i>0 && v[i]==v[i-1]) continue;
            //If ith ele is positive , then from here on sum won't be zero.
            if(v[i]>0) break;
            for(int j=i+1,k=n-1;j<k && k<n;){
                int jval=v[j],kval=v[k];
                int sum=v[i]+(kval+jval);
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                //If sum becomes zero push it to finans and find next pair of diff ele.
                else if(sum==0){
                    finans.push_back({v[i],v[j],v[k]});
                    while(v[j]==jval && j<k) j++;
                    while(v[k]==kval && k>j) k--;
                }
            }
        }
        return finans;
    }
};