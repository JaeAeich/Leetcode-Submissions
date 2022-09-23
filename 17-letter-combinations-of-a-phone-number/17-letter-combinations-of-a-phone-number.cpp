class Solution {
public:
    map<char,vector<char>> m;
    
    vector<string> finans={};
    
    void helper(string s,string ans="",int j=0){
        if(j>=s.size()){
            finans.push_back(ans);
            return ;
        }
        
        for(int i=0;i<m[s[j]].size();i++){
            ans+=m[s[j]][i];
            helper(s,ans,j+1);
            ans.pop_back();
        }
    }
    
    vector<string> letterCombinations(string s) {
        if(s=="") return finans;
        m['2']={'a','b','c'};
        m['3']={'d','e','f'};
        m['4']={'g','h','i'};
        m['5']={'j','k','l'};
        m['6']={'m','n','o'};
        m['7']={'p','q','r','s'};
        m['8']={'t','u','v'};
        m['9']={'w','x','y','z'};
        helper(s);
        return finans;
    }
};