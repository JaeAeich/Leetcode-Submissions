class Solution {
public:
    bool isValid(string s) {
        //creating a hash map to differentiate between opening and closing braces.
        map<char,int> m;
        m['(']=1;       
        m['[']=2;
        m['{']=3;
        m[')']=-1;
        m[']']=-2;
        m['}']=-3;
        stack<char> st;
        //iterating through braces.
        for(char c:s){
            /*if brace pair is found popping from stack and not pushing the
            closing brace in stack.
            Note : Closing brace should only pop the opening brace.
            ie: {+} =0 and }+{!=0 */
            if(!st.empty() && m[st.top()]+m[c]==0 && m[c]<0){
                st.pop();
                continue;
            }
            //else pushing the brace in.
            st.push(c);
        }
        //if stack is empty returning true.
        return st.empty();
    }
};