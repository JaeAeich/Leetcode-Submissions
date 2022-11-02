class Solution {
public:
//     //using freq array
//     int maxChunksToSorted(vector<int>& v) {
//         // making a sorted vector to compare the unsorte vec to.
//         vector<int> s;
//         s=v;
//         sort(begin(s),end(s));
//         int c=0;
//         //frequency hash map for sorted and unsorted vec.
//         unordered_map<int,int> f;
//         unordered_map<int,int> fs;
        
//         for(int i=0;i<v.size();i++){
//             //keeping tab of freq of ele of sorted and unsorted vec.
//             f[v[i]]++;
//             fs[s[i]]++;
//             //if at any point the freq becomes equal , that means it containts a chunk.
//             if(f==fs) {
//                 c++;
//             }
//         }
        
//         return c;
//     }
    int maxChunksToSorted(vector<int>& v) {
        vector<int> s=v;
        sort(begin(s),end(s));
        int c=0;
        long long int sum_v=0,sum_s=0;
        for(int i=0;i<v.size();i++){
            sum_v+=v[i];
            sum_s+=s[i];
            if(sum_s==sum_v){
                c++;
                sum_s=0;
                sum_v=0;
            }
        }
        return c;
    }
    
};