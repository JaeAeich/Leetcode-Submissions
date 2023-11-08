class Solution {
public:
    int longestSubsequence(vector<int>& v, int k) {
        map<int,int> m;
        for(int i = 0; i < v.size(); i++) {
            int val = v[i];
            if(m.find(val-k) != end(m)){
                m[val] = 1 + m[val - k];
            }
            else m[val] = 1;
        }
        int ans = 1;
        for(auto it = begin(m); it != end(m); it++) ans = max(ans, it->second);
        return ans;
    }
};