class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int m=v[0];
        int ans=0;
        for(int i=0;i<v.size();i++){
            m=max(m,v[i]);
            if(m==i){
                ans++;
            }
        }
        return ans;
    }
};