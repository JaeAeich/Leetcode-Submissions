class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans="";
        //constraint s[i].size<=200.
        for(int i=0;i<200;i++){
            if(i>=s[0].size()) break;
            char c=s[0][i];
            //"flag" checks if ith char is among all strings.
            //"alerts" checks out bound conditions.
            bool flag=true,alert=false;
            for(int j=0;j<s.size();j++){
                if(i>=s[j].size()){
                    alert=true;
                    break;
                }
                if(s[j][i]!=c){
                    flag=false;
                    break;
                }
            }
            if(alert) break;
            if(!flag) break;
            if(flag and !alert) ans+=c;
        }
        return ans;
    }
};