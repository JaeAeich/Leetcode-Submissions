class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        //removing special char and converting to lower case.
        for (auto c:s){
            //if the char is upper case
            if(isalpha(c) && tolower(c)!=c){
                temp+=tolower(c);
            }
            //if char is numeric then keep in string
            else if(isalnum(c)){
                temp+=c;
            }
        }
        //Two pointer to check palindrom.
        for(int i=0,j=temp.length()-1;i<=j;i++,j--){
            if(temp[i]!=temp[j]) return false;
        }
        return true;
    }
};