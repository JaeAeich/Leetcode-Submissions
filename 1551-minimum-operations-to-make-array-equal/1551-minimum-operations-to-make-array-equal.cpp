class Solution {
public:
    int minOperations(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            int oddnum=2*i-1;
            sum+=abs(oddnum-n);
        }
        return sum/2;
    }
};