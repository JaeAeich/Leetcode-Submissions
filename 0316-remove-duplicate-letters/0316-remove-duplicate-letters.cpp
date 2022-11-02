class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> f(26);
        vector<bool> inSt(26);
        stack<char> st;
        for(char c:s){
            f[c-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(inSt[s[i]-'a']) {
                f[s[i]-'a']--;
                continue;
            }
            while(!st.empty() && st.top()>s[i] && f[st.top()-'a']>0){
                inSt[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            inSt[s[i]-'a']=true;
            f[s[i]-'a']--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};