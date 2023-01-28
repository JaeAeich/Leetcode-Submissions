class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        //return empty is no solution found (not required).
        vector<int> ans={};
        for(int i=0,j=v.size()-1;i<j;){
            //if target found return positions.
            if(v[i]+v[j]==t){
                return {i+1,j+1};
            }
            //if sum is larger decrease sum by decreasing j.
            else if(v[i]+v[j]>t){
                j--;
            }
            //if sum is smaller, increase the sum by increasing i;
            else i++;
        }
        return ans;
    }
};