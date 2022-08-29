class Solution {
public:
    const int m=1e4+5;
    
    int missingNumber(vector<int>& nums) {
        vector<int> v(m);
        int n=nums.size();
        for(int val:nums){
            v[val]=1;
        }
        for(int i=0;i<n+1;i++){
            if(v[i]==0){
                return i;
            }
        }
        return -1;
    }
};