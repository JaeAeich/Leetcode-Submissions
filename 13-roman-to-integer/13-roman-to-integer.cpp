class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int ans=0,i=0;
        for(;i<s.size();){
            if(i==s.size()-1){
                ans+=m[s[i]];
                i++;
                continue;
            }
            if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X')){
                ans+=m[s[i+1]]-m[s[i]];
                i++;
            }
            else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')){
                ans+=m[s[i+1]]-m[s[i]];
                i++;
            }
            else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')){             
                ans+=m[s[i+1]]-m[s[i]];
                i++;
            }
            else{
                ans+=m[s[i]];
            }
            i++;
        }
        return ans;
    }
};