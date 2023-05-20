class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(!v.size()) return 0;
        sort(begin(v),end(v));
        int ans = 1;
        int c=1;
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]) continue;
            if(v[i]==v[i-1]+1){
                c++;
                ans=max(ans,c);
            }
            else{
                c=1;
            }
        }
        return ans;
    }
};