class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int c=0,ans=INT_MIN;
        for(int i=0;i<v.size();i++){
            if(v[i]==1) {
                c++;
            }
            else{
                ans=max(ans,c);
                c=0;
            }
        }
        if(c){
            ans=max(ans,c);
        }
        return ans==INT_MIN?0:ans;
    }
};