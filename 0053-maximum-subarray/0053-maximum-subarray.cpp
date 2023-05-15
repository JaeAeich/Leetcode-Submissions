class Solution {
public:
    int maxSubArray(vector<int>& v) {
        //Store a ans variable.
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<v.size();i++){
            //if the sum ever goes negative, then that can't be the part of max subarray.
            if(sum<0){
                sum=0;
            }
            sum+=v[i];
            ans=max(sum,ans);
        }
        return ans;
    }
};