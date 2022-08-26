class Solution {
public:    
    vector<vector<int>> ans={{1}};
    
    vector<int> helper(int n){
        //Since ans vector already has {1}, base condition is set for 2.
        if(n==2){
            vector<int> base={1,1};
            ans.push_back(base);
            return base;
        }
        //Recursively getting the (n-1)th row. 
        vector<int> prev=helper(n-1);
        vector<int> curr={1};
        //Adding its element to curr vector.
        for(int i=1;i<prev.size();i++){
            int x=prev[i]+prev[i-1];
            curr.push_back(x);
        }
        curr.push_back(1);
        ans.push_back(curr);
        return curr;
    }
    
    vector<vector<int>> generate(int n) {
        if(n==1) return ans;
        helper(n);
        return ans;
    }
};