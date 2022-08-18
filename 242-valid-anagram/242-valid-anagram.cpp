class Solution {
public:    
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        for(int i=0;s[i]!='\0';i++){
            int idx=s[i]-'a';
            v[idx]++;
        }
        for(int i=0;t[i]!='\0';i++){
            int idx=t[i]-'a';
            v[idx]--;
        }
        for(int i=0;i<26;i++){
            if(v[i]!=0) return false;
        }
        return true;
    }
};