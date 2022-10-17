class Solution {
public:
    //explanation : https://www.youtube.com/watch?v=OINnBJTRrMU&ab_channel=AdityaVerma
    int findPeakElement(vector<int>& v) {
        int n=v.size();
        if(n==1) return 0;
        int lo=0,hi=n-1;
        int ans=-1;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if((mid==0 && v[mid]>v[mid+1]) || (mid==n-1 && v[mid]>v[mid-1]) || (v[mid]>v[mid+1] && v[mid]>v[mid-1])) {
                ans=mid;
                break;
            }
            else if(v[mid+1] > v[mid]){
                lo= mid+1;
            }
            else {
                hi=mid-1;
            }
        }
        return ans;
    }
};