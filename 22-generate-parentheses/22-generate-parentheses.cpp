class Solution {
public:
    vector<string> finans={};
    void helper(int n,string ans="",int o=0,int c=0){
        //if closing brackets are more than opening, return .
        if(o>n || c>n || c>o) return;
        if(c+o==2*n && o==c){
            finans.push_back(ans);
        }
        //either ith pos can have '(' or ')'
        ans+='(';
        helper(n,ans,o+1,c);
        ans.pop_back();
        ans+=')';
        helper(n,ans,o,c+1);
    }
    //driver code
    vector<string> generateParenthesis(int n) {
        helper(n);
        return finans;
    }
};