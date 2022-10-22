class Solution {
public:
    int trap(vector<int>& v) {
        vector<int> htl(v.size());
        vector<int> htr(v.size());
        int htn=INT_MIN;
        for(int i=0;i<v.size();i++){
            if(htn<v[i]){
                htn=v[i];
            }
            htl[i]=htn;
        }
        htn=INT_MIN;
        for(int i=v.size()-1;i>=0;--i){
            if(htn<v[i]){
                htn=v[i];
            }
            htr[i]=htn;
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=min(htl[i],htr[i])-v[i];
        }
        return ans;
    }
};