class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n = v.size();
        int zero = 0;
        int lo = 0, hi = 0;
        
        int ans = 0;
        
        while(hi < n){
            if(v[hi] == 0){
                zero++;
            }
            
            while(zero > k){
                if(v[lo] == 0) zero--;
                lo++;
            }
            
            ans = max(ans, hi - lo + 1);
            
            hi++;
        }
        
        return ans;
    }
};