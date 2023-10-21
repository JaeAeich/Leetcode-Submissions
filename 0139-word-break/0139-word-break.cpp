class Solution {
private:
    bool check(string &s, int i, string &t){
        if(t.size() > s.size() - i) return false;
        for(int k = 0; k < t.size(); k++){
            if(t[k] != s[i + k]) return false;
        }
        
        return true;
    }
    
    bool helper(vector<int> &dp, vector<string> & v, string s, int i = 0){
        if(i >= s.size()) return true;
        
        bool ret = false;
        if(dp[i] != -1) return dp[i];
        for(auto str: v){
            if(str[0] == s[i] && check(s, i, str)){
                ret = ret || helper(dp, v, s, i + str.size());
            }
        }
        
        return dp[i] = ret;
    }
public:
    bool wordBreak(string s, vector<string>& v) {
        vector<int> dp(s.size(), -1);
        return helper(dp, v, s);
    }
};