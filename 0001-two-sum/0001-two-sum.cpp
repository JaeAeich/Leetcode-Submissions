class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        vector<pair<int,int>> v;
        
        //storing the input with idx 
        for(int i=0;i<nums.size();i++) v.push_back({nums[i],i});
        
        //sorting the input
        sort(begin(v),end(v));
        vector<int> ans = {-1,-1};
        
        //iterating and finding the target 
        for(int i=0,j=v.size()-1;i<j;){
            int temp = v[i].first+v[j].first;
            
            //it found return idx
            if(temp==t){
                ans = {v[i].second,v[j].second};
                break;
            }
            
            //if sum is greater increase the sum and vice versa
            else if(temp>t) j--;
            else i++;
        }
        return ans;
    }
};