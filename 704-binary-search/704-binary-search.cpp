class Solution {
public:
    int search(vector<int>& v, int t) {
        //If not found, return -1 hence, initialising ans with -1.
        int ans=-1;
        int lo=0,hi=v.size()-1;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            //If found break.
            if(v[mid]==t){
                ans=mid;
                break;
            }
            else if (v[mid]>t){
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};