class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> string;
        multiset<char> string1;
        for(char ch: s){
            string.insert(ch);
        }
        for(char ch: t){
            string1.insert(ch);
        }
        return string==string1;
    }
};