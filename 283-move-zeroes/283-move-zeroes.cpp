class Solution {
public:
//  // brute force
    // void moveZeroes(vector<int>& v) {
    //     vector<int> temp;
    //     int c=0;
    //     for(int i=0;i<v.size();i++){
    //         if(v[i]) temp.push_back(v[i]);
    //         else c++;
    //     }
    //     while(c--){
    //         temp.push_back(0);
    //     }
    //     v=temp;
    // }
    
    //in place 
    void moveZeroes(vector<int>& v) {
        int c=0,i=0;
        for(;i<v.size();i++){
            if(!v[i]) c++;
            else v[i-c]=v[i];
        }
        for(int i=v.size()-c;i<v.size();i++){
            v[i]=0;
        }
    }
    
};