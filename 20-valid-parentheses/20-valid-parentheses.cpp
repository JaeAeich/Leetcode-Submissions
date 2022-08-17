class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('a');
        map<char,char> m;
        m['{']='}';
        m['(']=')';
        m['[']=']';
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(m[st.top()]==s[i]){
                    st.pop();
                }
                else return false;
            }
        }
        if(st.top()=='a') return true;
        return false;
    }
};