class Solution {
public:
    bool valid(vector<int>& p, int h,int mid){
        int t=0;
        for(int i=0;i<p.size();i++){
            t+=(p[i]*1.0+mid-1)/mid;
        }
        return t<=h;
    }
    
    int minEatingSpeed(vector<int>& p, int h) {
        int lo =1,hi =INT_MAX;
        int ans=-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(valid(p,h,mid)) {
                ans=mid;
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        return ans;
    }
};