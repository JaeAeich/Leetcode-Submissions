class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        map<char,bool> v;
        v['a' - 'a'] = 1;
        v['e' - 'a'] = 1;
        v['i' - 'a'] = 1;
        v['o' - 'a'] = 1;
        v['u' - 'a'] = 1;
        v['A' - 'a'] = 1;
        v['E' - 'a'] = 1;
        v['I' - 'a'] = 1;
        v['O' - 'a'] = 1;
        v['U' - 'a'] = 1;
        for(int i = 0; i < s.size(); i++){
            if(v.find(s[i] - 'a') != v.end() && v[s[i] - 'a']){
                st.push(s[i]);
                s[i] = '*'; 
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
};