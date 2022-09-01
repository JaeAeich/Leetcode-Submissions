class Solution {
public:
    //Using binary search 
    int mySqrt(int x) {
        int lo=1,hi=x;
        //Setting ans to zero so if n is zero loop is terminated and 0 is returned.
        int ans=0;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if((long long )mid*mid>=x) ans=mid,hi=mid-1;
            else lo=mid+1;
        }
        return (long long )ans*ans>x?ans-1:ans;
    }
};