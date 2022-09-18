class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') continue;
            string temp="";
            do{
                if(i==s.size() || s[i]==' ') break;
                temp+=s[i];
                i++;
            }
            while(i<=s.size()-1);
            if(ans.empty()) ans+=temp;
            else ans=temp+" "+ans;
        }
        return ans;
    }
};