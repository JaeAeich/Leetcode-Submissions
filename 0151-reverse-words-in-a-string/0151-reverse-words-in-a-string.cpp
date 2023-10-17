class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                string word = "";
                do{
                    word += s[i++];
                }
                while(i < s.length() && s[i] != ' ');
                ans = word + " " + ans;
            }
        }
        return ans.substr(0,ans.length()-1);
    }
};