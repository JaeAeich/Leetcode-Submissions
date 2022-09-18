class Solution {
public:
    int ans=0;
    //Rotating the digits.
    void check(string s){
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='3' ||s[i]=='4' ||s[i]=='7'){
                return;
            }
            else if(s[i]=='8' || s[i]=='1' || s[i]=='0') temp+=s[i];
            else if(s[i]=='5') temp+='2';
            else if(s[i]=='2') temp+='5';
            else if(s[i]=='6') temp+='9';
            else temp+='6';
        }
        if(temp!=s) ans++;
    }
    int rotatedDigits(int n) {
        for(int i=1;i<=n;i++){
            check(to_string(i));
        }
        return ans;
    }
};