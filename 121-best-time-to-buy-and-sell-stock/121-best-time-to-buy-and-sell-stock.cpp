class Solution {
public:
    //Time complexity :- O(N)
    //Space complexity :-O(N)
    int maxProfit(vector<int>& v) {
        int n=v.size(),max_yet=v[n-1];
        vector<int> max_ele(n);
        //Storing maximum ele after ith index of array.
        for(int i=n-1;i>=0;i--){
            if(v[i]>=max_yet){
                max_yet=v[i];
            }
            max_ele[i]=max_yet;
        }
        int ans=INT_MIN;
        //checking for all index, max profit.
        for(int i=0;i<n;i++){
            ans=max(max_ele[i]-v[i],ans);
        }
        return ans;
    }
};