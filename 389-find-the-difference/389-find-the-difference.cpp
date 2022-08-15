class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> m;
        for(int i=0;s[i]!='\0';i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=1;
            }
            else m[s[i]]++;
        }
        char ret;
        for(int i=0;t[i]!='\0';i++){
            if(m.find(t[i])==m.end()){
                ret =t[i];
                break;
            }
            else {
                if(m[t[i]]) m[t[i]]--;
                else {
                    ret=t[i];
                    break;
                }
            }
        }
        return ret ;
    }
};