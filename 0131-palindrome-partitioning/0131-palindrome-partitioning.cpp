class Solution {
private:
    vector<vector<string>> ans = {};

    // Check if the strig is a palindorm 
    bool isPal(string s){
        for(int i = 0, j = s.length() - 1; i < j;){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    void helper(string s, string soFar = "", vector<string> ans_here = {}, int i = 0){
        if(i >= s.length()){
            if(soFar == ""){
                ans.push_back(ans_here);
            }
            return;
        }

        // Take this char and check if this makes a Pal
        soFar += s[i];
        if(isPal(soFar)){
            ans_here.push_back(soFar);
            helper(s, "", ans_here, i+1);
            ans_here.pop_back();
        }
        // If string so far isn't a palindrom
        helper(s, soFar, ans_here, i+1);
    }

    
public:
    vector<vector<string>> partition(string s) {
        helper(s);
        return ans;
    }
};