class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        v1.resize(m);
        vector<int> ans={};
        for(int i=0,j=0;i<m || j<v2.size();){
            if(j==v2.size()){
                for(int k=i;k<v1.size();k++){
                    ans.push_back(v1[k]);
                }
                break;
            }
            if(i==v1.size()){
                for(int k=j;k<n;k++){
                    ans.push_back(v2[k]);
                }
                break;
            }
            
            if(v1[i]<v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else{
                ans.push_back(v2[j]);
                j++;
            }
        }
        v1=ans;
    }
};