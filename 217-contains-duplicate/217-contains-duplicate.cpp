class Solution {
public:
    // //sort
    // bool containsDuplicate(vector<int>& v) {
    //     sort(v.begin(),v.end());
    //     for(int i=0;i<v.size()-1;i++){
    //         if(v[i]==v[i+1]) return true;
    //     }
    //     return false;
    // }
    
//     // brute force (tle)
//     bool containsDuplicate(vector<int>& v) {
//         for (int i=0;i<v.size()-1;i++){
//             for(int j=i+1;j<v.size();j++){
//                 if(v[i]==v[j]) return true;
//             }
//         }
//         return false;
//     }
//     // Using hash map, TC:O(N), SC:O(N)
//     bool containsDuplicate(vector<int>& v) {
//         map<int,int> m;
//         for(int val:v){
//             if(m[val]){
//                 return true;
//             }
//             else m[val]=1;
//         }
//         return false;
//     }
    
    //hash
    bool containsDuplicate(vector<int>& v) {
        set<int> s;
        for(int val:v){
            if(s.find(val)!=s.end()){
                return true;
            }
            s.insert(val);
        }
        return false;
    }
};
