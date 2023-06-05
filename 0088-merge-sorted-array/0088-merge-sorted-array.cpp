class Solution {
public:
    // Using extra space
    void merge(vector<int>& v1, int n, vector<int>& v2, int m) {
        int i=0,j=0;
        vector<int> ans = {};
        v1.resize(n);
        
        // Two pointer
        while(i<n && j<m){
            if(v1[i]>=v2[j]){
                ans.push_back(v2[j]);
                j++;
            }
            else{
                ans.push_back(v1[i]);
                i++;
            }
        }
        while(i<n) ans.push_back(v1[i++]);
        while(j<m) ans.push_back(v2[j++]);
        
        v1=ans;
    }
};