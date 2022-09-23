class Solution {
public:
    bool pal(string s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int c=0,n=s.size();
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(pal(temp)) c++;
            }
        }
        return c;
    }
};