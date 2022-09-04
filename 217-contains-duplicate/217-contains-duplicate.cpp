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