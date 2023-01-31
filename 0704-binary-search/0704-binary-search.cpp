class Solution {
public:
    //implementing binary search, TC:O(log(n))), SC:O(1)
    int search(vector<int>& v, int t) {
        int lo=0,hi=v.size()-1;
        //intialising -1 if target is not found.
        int ans=-1;
        while(lo<=hi){
            //Going to the mid of the index.
            int mid=lo+(hi-lo)/2;
            //If target found then break and return .
            if(v[mid]==t) {
                ans=mid;
                break;
            }
            //If the founf ele is less then go to right.
            else if(v[mid]<t){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};