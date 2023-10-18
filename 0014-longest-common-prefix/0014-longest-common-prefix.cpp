class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int minn = INT_MAX;
        for(auto s : strs){
            int len = s.length();
            minn = min(len, minn);
        }
        bool flag = true;
        for(int i = 0; i < minn; i++){
            for(auto s : strs){
                if(strs[0][i] != s[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans += strs[0][i];
            }
        }
        return ans;
    }
};