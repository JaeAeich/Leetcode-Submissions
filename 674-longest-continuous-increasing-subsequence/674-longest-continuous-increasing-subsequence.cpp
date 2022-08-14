class Solution {
public:
    int findLengthOfLCIS(vector<int>& v) {
        int len=0,ans=0;
        for(int i=0;i<v.size();i++){
            if(i==0 || v[i-1]<v[i]){
                len++;
            }
            else len=1;
            ans=max(ans,len);
        }
        return ans;
    }
};