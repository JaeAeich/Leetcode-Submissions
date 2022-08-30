class Solution {
public:
    int searchInsert(vector<int>& v, int t) {
        int n=v.size();
        int lo=0,hi=n-1,ans;
        if(t<v[0]){
            return 0;
        }
        if(v.back()<t){
            return n;
        }
        //Implementation of stl lower_bound.
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(v[mid]>=t){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};