class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> m;
        // map closing backets
        m['{']='}';
        m['(']=')';
        m['[']=']';
        //push brackets in stack if its opening bracket.
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                // if its not opening and top is its counter part then pop from stack. if stack is empty you cant push closing bracket so return false.
                if(st.empty()) return false;
                if(m[st.top()]==s[i]){
                    st.pop();
                }
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};