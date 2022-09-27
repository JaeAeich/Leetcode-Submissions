class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    
    int maxDepth(string s) {
        int ans=0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            //Pushing opening braces to keep count of max depth.
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')') st.pop();
            
            ans=max(ans,st.size());
        }
        return ans;
    }
};