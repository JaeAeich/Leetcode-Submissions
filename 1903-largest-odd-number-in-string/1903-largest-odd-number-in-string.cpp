class Solution {
public:
    string largestOddNumber(string s) {
        int idx=0;
        //finding the last odd num, since that will make the largest odd num.
        for(int i=s.size()-1;i>=0;i--){
            if(stoi(to_string(s[i]))%2!=0){
                idx=i;
                break;
            }
        }
        if(stoi(to_string(s[idx]))%2==0) return "";
        s=s.substr(0,idx+1);
        return s;
    }
};