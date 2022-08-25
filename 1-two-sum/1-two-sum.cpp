class Solution {
public:
    // Time coplexity:- O(N), Space complexity:- O(N)
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        vector<pair<int,int>> v;
        //storing values and index so we can sort it later.
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(begin(v),end(v));
        int lo=0,hi=n-1;
        while(hi>lo){
            int lo_val=v[lo].first,hi_val=v[hi].first;
            int sum=lo_val+hi_val;
            //If sum is less than target increase the sum by adding a higher ele.
            if(sum<t){
                lo++;
            }
            else if(sum>t){
                hi--;
            }
            else{
                return {v[lo].second,v[hi].second};
            }
        }
        return {};
    }
};