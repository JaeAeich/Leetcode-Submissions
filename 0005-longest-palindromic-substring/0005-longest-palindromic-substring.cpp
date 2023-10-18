class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // For Odd-Length Palindromes
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > ans.length()) {
                    ans = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
            
            // For Even-Length Palindromes
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > ans.length()) {
                    ans = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
        }
        
        return ans;
    }
};
