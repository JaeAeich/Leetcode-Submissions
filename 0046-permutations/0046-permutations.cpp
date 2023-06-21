class Solution {
private:
    // Final ans to be returned
    vector<vector<int>> finans = {};
    
    // Calculate the permutations
    void helper(vector<int>& v, vector<bool> &taken, vector<int> &ans){
        if(ans.size() == v.size()){
            finans.emplace_back(ans);
            return;
        }
        
        for(int i=0; i<v.size(); i++){
            // If this ele is not taken 
            if(!taken[i]){
                
                // Mark it as taken
                taken[i] = 1;
                
                // Take it into answer as this is one of the perms
                ans.push_back(v[i]);
                helper(v, taken, ans);
                
                // Backtrack to generate other possibilities
                ans.pop_back();
                taken[i] = 0;
            }
        }
    }
public:
    // Driver code
    vector<vector<int>> permute(vector<int>& v) {
        vector<bool> taken(v.size());
        vector<int> ans = {};
        helper(v, taken, ans);
        return finans;
    }
};