class Solution {
public:
    bool valid(vector<int> &v,int m, int k, int mid){
        int tot=0;
        int c=0;
        //Counting no of bouquets that are possible
        for(int val:v){
            if(val<=mid){
                c++;
            }
            else{
                tot+=c/k;
                c=0;
            }
        }
        //Adding rest of bouquets that might not have been added in the loop.
        tot+=c/k;
        return tot>=m;
    }
    
    int minDays(vector<int>& v, int m, int k) {
        if(m*k>v.size()){
            return -1;
        }
        int lo=1,hi=1e9;
        int ans=-1;
        //Binary search
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(valid(v,m,k,mid)){
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