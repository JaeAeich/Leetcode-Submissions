class Solution {
public:
    //Finding a capacity using binary search(say mid).
    bool isValid(vector<int> &v, int mid, int d){
        int sum=0,c=0;
        for(int val:v){
            if(sum+val>mid){
                c++;
                sum=0;
            }
            sum+=val;
        }
        if(sum>0) c++;
        return c<=d;
    }
    //Binary search
    int shipWithinDays(vector<int>& v, int d) {
        int ans=-1;
        int lo=*max_element(begin(v),end(v)),hi=accumulate(begin(v),end(v),0);
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(isValid(v,mid,d)) ans=mid,hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }
};