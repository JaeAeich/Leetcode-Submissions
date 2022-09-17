class Solution {
public:
    string genStr(int n, int b){
        string s="";
        while(n){
            s+=to_string(n%b);
            n/=b;
        }
        return s;
    }
    
    bool isPal(string s){
        int n=s.size();
        for(int i=0;i<=n/2;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            if(!isPal(genStr(n,i))) return false;
        }
        return true;
    }
};