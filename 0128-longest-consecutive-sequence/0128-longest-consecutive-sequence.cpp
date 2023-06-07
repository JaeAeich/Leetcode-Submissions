class Solution {
public:
    // Using sorting and counting the freq
    int longestConsecutive(vector<int>& v) {
        if(v.size()<=1) return v.size();
        sort(begin(v),end(v));
        int ans = 1;
        int f=1;
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]) continue;
            // If consecutve count the freq
            if(v[i]-v[i-1]==1){
                f++;
                ans=max(ans,f);
            }
            // If a non-consecutive ele found, start a new subsequence
            else{
                f=1;
            }
        }
        return ans;
    }
};