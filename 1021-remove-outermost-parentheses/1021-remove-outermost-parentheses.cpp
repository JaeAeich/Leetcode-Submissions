class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            int c=0,o=0;
            string temp="";
            //Decompositioning into premitive braces, acc ques.
            do{
                temp+=s[i];
                if(s[i]=='(') o++;
                else c++;
                if(c!=o) i++;
            }
            while(c!=o);
            //Removing the outer braces.
            ans+=temp.substr(1,temp.size()-2);
        }
        return ans;
    }
};