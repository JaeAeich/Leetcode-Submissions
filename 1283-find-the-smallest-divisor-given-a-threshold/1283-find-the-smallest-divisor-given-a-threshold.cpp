class Solution {
public:
    typedef long long int ll;
    //Dividing all the ele with mid ans summing them up.
    //Returning true if its less than or equal to threshold.
    bool valid(vector<int> &v, int &m,int &t){
        ll sum=0;
        for(int val:v){
            sum+=(val+m-1)/m;
        }
        return sum<=t;
    }
    
    int smallestDivisor(vector<int>& v, int t) {
        int lo=1,hi=1e6;
        int ans=-1;
        //Binary search
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(valid(v,mid,t)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};