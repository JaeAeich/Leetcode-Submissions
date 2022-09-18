class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
        //map all the char to char of other string.
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=t[i];
            }
            //If one char get mapped to 2 chars return false.
            if(m[s[i]]!=t[i]) return false;
        }
        map<char,int> mp;
        //checking if the chars of t are also having one to one mapping.
        for(auto it=m.begin();it!=m.end();it++){
            mp[it->second]++;
            if(mp[it->second]>1) return false; 
        }
        return true;
    }
};