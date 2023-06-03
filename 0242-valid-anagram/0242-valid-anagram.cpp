class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        for(auto c: s) m1[c]++;
        for(auto c: t) m2[c]++;
        return m1==m2;
    }
};