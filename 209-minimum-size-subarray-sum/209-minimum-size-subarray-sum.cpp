class Solution {
public:
    int minSubArrayLen(int t, vector<int>& v) {
        int sum=0,ans=INT_MAX;
        int j=0,i=0;
        while(j<v.size()){
            sum+=v[j++];
            while(sum>=t){
                ans=min(ans,j-i);
                sum-=v[i++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};