class Solution {
public:
    bool isAnagram(string s, string t) {
        // freq count
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        
        // count freq
        for(auto c: s) m1[c-'a']++;
        for(auto c: t) m2[c-'a']++;
        
        // If freq of each char is equal in both, then they are anagram
        return m1==m2;
    }
};