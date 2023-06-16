class Solution {
public:
    // Store final ans
    vector<vector<string>> finans = {};
    
    // Checks if str a is palindrome
    bool check(string a){
        int i=0,j=a.length()-1;
        while(i<=j){
            if(a[i]!=a[j]) return false;
            i++,j--;
        }
        return true;
    }
    
    // Helper function
    void helper(string s, string strAns ="", vector<string> ans={}, int i=0){
        if(i>=s.length()){
            if(!strAns.empty() && check(strAns)){
                ans.push_back(strAns);
                finans.push_back(ans);
            }
            return ;
        } 
        
        // Take the ith ele
        strAns += s[i];
        
        // If this makes a palindrome, find another palindrome after this
        if(check(strAns)){
            ans.push_back(strAns);
            helper(s,"",ans,i+1);
            ans.pop_back();
        }

        // Make is bigger str, maybe that makes a palindrome
        helper(s,strAns,ans,i+1);
    }
    
    vector<vector<string>> partition(string s) {
        helper(s);
        return finans;
    }
};