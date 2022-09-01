class Solution {
public:
    bool valid(vector<int> v,int m){
        if(m==0 || v[m]>=v[m-1]) return true;
        return false;
    }
    
    int peakIndexInMountainArray(vector<int>& v) {
        int n=v.size();
        int lo=0,hi=n-1;
        int ans;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            //If the prev ele is smaller then peak is ahead of index m.
            if(valid(v,mid)) ans=mid, lo=mid+1;
            //Else search in the back .
            else hi=mid-1;
        }
        return ans;
    }
};