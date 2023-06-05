class Solution {
public:
//     // Using extra space
//     void merge(vector<int>& v1, int n, vector<int>& v2, int m) {
//         int i=0,j=0;
//         vector<int> ans = {};
//         v1.resize(n);
        
//         // Two pointer
//         while(i<n && j<m){
//             if(v1[i]>=v2[j]){
//                 ans.push_back(v2[j]);
//                 j++;
//             }
//             else{
//                 ans.push_back(v1[i]);
//                 i++;
//             }
//         }
//         while(i<n) ans.push_back(v1[i++]);
//         while(j<m) ans.push_back(v2[j++]);
        
//         v1=ans;
//     }
    
  // Without using extra space
    void merge(vector<int>& v1, int n, vector<int>& v2, int m) {
        /*
        Since both the arrays are sorted, we can put all the smaller to v1 
        and then sort both the arrays, this will make sure that they are in 
        correct order.
        */
        int i=n-1,j=0;
        while(i>=0 && j<m){
            if(v1[i]>v2[j]) swap(v1[i],v2[j]);
            i--;
            j++;
        }
        
        // Sorting 
        sort(begin(v1),begin(v1)+n);
        sort(begin(v2),end(v2));
        
        // Rearranging
        i=n,j=0;
        while(j<m){
            v1[i++]=v2[j++];
        }
    }
    
};