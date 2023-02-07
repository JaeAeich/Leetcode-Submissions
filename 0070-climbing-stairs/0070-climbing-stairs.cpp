class Solution {
public:
    //using recursion
    // int climbStairs(int n) {
    //     if(n==0) return 0;
    //     if(n==1) return 1;
    //     if(n==2) return 2;
    //     return climbStairs(n-1)+climbStairs(n-2);
    // }
    
    //using dp
    int climbStairs(int n) {
        //base case
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        //no. of ways to get to the stair curr -1 and curr -2
        int back1=2,back2=1;
        int tillHere=0;
        for(int i=3;i<n+1;i++){
            //steps needed toreach this stair.
            tillHere=back1+back2;
            //for next stair changing updating the no. of way of reaching this stair -1 and -1.
            back2=back1;
            back1=tillHere;
        }
        return tillHere;
    }
};