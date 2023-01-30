class Solution {
public:
    vector<string> finans;
    
    void helper(int n, int o=0,int c=0, string ans=""){
        //if string is completed.
        if(o+c==2*n) {
            finans.push_back(ans);
            return ;
        }
        //if opening braces are left, then put a opening brace.
        if(o<n) {
            ans+='(';
            helper(n,o+1,c,ans);
            ans.pop_back();
        }
        //if closing brace can be put, ie opening braces are greater than closing.
        if(c<o){
            ans+=')';
            helper(n,o,c+1,ans);
            ans.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        helper(n);
        return finans;
    }
};