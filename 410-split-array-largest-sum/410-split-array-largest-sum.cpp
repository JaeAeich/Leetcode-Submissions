class Solution {
public:
    typedef long long int ll;
    
    //Summing up sub arrays, if it goes above mid, then increment the counter.
    //If counter goes above m,(ie total subarrays formed with each totaling less or equal to mid), return false.
    bool isValid(vector<int> &v,int m,int mid){
        int c=0;
        ll sum=0;
        for(int val:v){
            if(sum+val>mid){
                c++;
                sum=0;
            }
            sum+=val;
        }
        if(sum>0) c++;
        return c<=m;
    }
    //Binary search
    int splitArray(vector<int>& v, int m) {
        int lo=*max_element(v.begin(),v.end()),hi=1e9;
        int ans=-1;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(isValid(v,m,mid)) ans=mid,hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }
};