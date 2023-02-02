class Solution {
public:
    int findMin(vector<int>& v) {
        //search space 
        int lo =0, hi =v.size()-1;
        int ans=-1;
        //binary search 
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(v[mid]-v[0]<0){
                ans=v[mid];
                hi=mid-1;
            }
            else lo=mid+1;
        }
        //if ans not found, then array is not rotated.
        return ans==-1?v[0]:ans;
    }
};