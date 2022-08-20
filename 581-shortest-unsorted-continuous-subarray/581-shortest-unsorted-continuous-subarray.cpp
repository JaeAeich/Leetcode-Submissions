class Solution {
public:
    // using sorting and two pointers
    int findUnsortedSubarray(vector<int>& v2) {
        vector<int> v1=v2;
        sort(begin(v2),end(v2));
        if(v1==v2) return 0;
        int ai=0,jae=v1.size()-1;
        for(int i=0,j=v1.size()-1;i<j;){
            if(v1[i]==v2[i]) i++;
            if(v1[j]==v2[j]) j--;
            
            if(i==ai && j==jae) break;
            
            ai=i,jae=j;
        }
        return -ai+jae+1;
    }
};