class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        set<vector<int>> s={};
        vector<vector<int>> ans={};
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-2;i++){
            if(v[i]>0) break;
            if (i > 0 and v[i] == v[i-1]) continue;
            for(int j=i+1,k=v.size()-1;j<k;){
                int sum=v[i]+v[j]+v[k];
                if(sum==0){
                    s.insert({v[i],v[j],v[k]});
                    ++j;
                    --k;
                }
                else if(sum>0) --k;
                else  ++j;
            }
        }
        
        for(vector<int> vec: s){
            ans.push_back(vec);
        }
        
        return ans;
    }
};