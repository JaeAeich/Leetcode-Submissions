class Solution {
public:
    typedef long long int ll;
    //Checking if koko can eat all the bananas at mid bananas/hour speed.
    bool valid(vector<int> &v,int mid,int t){
        ll ans=0;
        for(int val:v){
            ans+=(val+mid-1)/mid;
        }
        return ans<=t;
    }
    
    int minEatingSpeed(vector<int>& v, int h) {
        int lo=1,hi=1e9;
        int ans=-1;
        //Binary search
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(valid(v,mid,h)) ans=mid,hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }
};