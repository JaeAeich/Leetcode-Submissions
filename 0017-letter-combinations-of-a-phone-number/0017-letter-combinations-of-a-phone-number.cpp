#include<bits/stdc++.h>

class Solution {
public:
    vector<string> finans={}; 
    
    void DFS(string &s, vector<vector<char>> &l, int i=0, string ans = ""){
        if(i>=s.length()){
            finans.push_back(ans);
            return;
        }
        string temp ="" ;
        temp +=s[i];
        int pos=stoi(temp);
        for(auto c : l[pos-2]){
            ans+=c;
            DFS(s,l,i+1,ans);
            ans.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(!digits.length()) return {};
        vector<vector<char>> letter= {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        DFS(digits,letter);
        return finans;
    }
};