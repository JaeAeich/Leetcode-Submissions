class Solution {
public:
//     //Recursion ,TLE
//     int c=0;
//     void helper(int n){
//         if(n<0) return ;
//         if(n==0) c++;
        
//         helper(n-1);
//         helper(n-2);
//     }
    
//     int climbStairs(int n) {
//         helper(n);
//         return c;
//     }
    //dynamic programming O(N)
    int climbStairs(int n) {
        vector<int> v={0,1,2,3};
        for(int i=4;i<n+1;i++){
            v.push_back(v[i-1]+v[i-2]);
        }
        return v[n];
    }
    
};