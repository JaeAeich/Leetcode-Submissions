class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int sum=0;
        int ans=INT_MIN;
        for(int i=0;i<v.size();i++){
            //Adding ith ele.
            sum+=v[i];
            //keeping track of the max sum till now.
            ans=max(ans,sum);
            //If sum ever gets neg then it can't contibute to largest sum subarray.
            //So start a new subarray.
            if(sum<0){
                sum=0;
                continue;
            }
        }
        return ans;
    }
};