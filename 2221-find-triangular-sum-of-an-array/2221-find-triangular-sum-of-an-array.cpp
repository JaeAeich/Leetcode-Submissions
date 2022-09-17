class Solution {
public:
//     //brute force
//     //make a new vector of sum
//     vector<int> addBruh(vector<int> v){
//         vector<int> ans={};
//         for(int i=0;i<v.size()-1;i++){
//             int s=(v[i]+v[i+1])%10;
//             ans.push_back(s);
//         }
//         return ans;
//     }

//     int triangularSum(vector<int>& nums) {
//         if(nums.size()==1) return nums[0]%10;
//         while(true){
//             //set nums to the new vector produced.
//             nums=addBruh(nums);
//             if(nums.size()==1) break ;
//         }
//         return nums[0];
//     }
    
    //Optimal
    int triangularSum(vector<int>& nums){
        while(nums.size()!=1){
            int n=nums.size();
            for(int i=0;i<n-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            nums.resize(n-1);
        }
        return nums[0];
    }
};