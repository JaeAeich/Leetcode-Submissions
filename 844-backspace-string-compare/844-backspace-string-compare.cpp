class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // declaring to stacks
        stack<char> st1;
        stack<char> st2;
        int n=s.length();
        int m=t.length();
        
        //pushing ele if its not backspace
        for(int i=0;i<n;i++){
            if(s[i]!='#'){
                st1.push(s[i]);
            }
            else{
                // if its backspace pop the top ele iff its not empty
                if(!st1.empty())st1.pop();
            }
        }
        for(int i=0;i<m;i++){
            if(t[i]!='#'){
                st2.push(t[i]);
            }
            else{
                if(!st2.empty())st2.pop();
            }
        }
        if(st1.size()!=st2.size()) return false;
        // if they are of same size check its content.
        while(!st1.empty()){
            if(st1.top()!=st2.top()) return false;
            st1.pop();
            st2.pop();
        }
        return true;
    }
};