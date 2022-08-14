class Solution {
public:
    int findLengthOfLCIS(vector<int>& v) {
        int len=0,ans=0;
        for(int i=0;i<v.size();i++){
            if(i==0 || v[i]>v[i-1]) ans=max(ans,++len);
            else len=1;
        }
        return ans;
    }
};