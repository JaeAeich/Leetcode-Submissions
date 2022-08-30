class Solution {
public:
    int findMin(vector<int>& v) {
        int n=v.size();
        int lo=0,hi=n-1,ans;
        //Finding pivot
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(v[mid]-v[0]<0) ans=mid,hi=mid-1;
            else lo=mid+1;
        }
        //If the array wasn't rotated then piv will be greater than n-1
        return ans>n-1?v[0]:v[ans];
    }
};