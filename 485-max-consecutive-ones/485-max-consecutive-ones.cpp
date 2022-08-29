class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int n=v.size();
        int len=0,ans=0;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                len=0;
                continue;
            }
            len+=1;
            ans=max(ans,len);
        }
        return ans;
    }
};