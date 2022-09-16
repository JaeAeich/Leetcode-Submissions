class Solution {
public:
    // //O(N)
    // int kthFactor(int n, int k) {
    //     vector<int> v;
    //     v.push_back(1);
    //     for(int i=2;i<=n;i++){
    //         if(n%i==0) v.push_back(i);
    //     }
    //     return k>v.size()?-1:v[k-1];
    // }
    //O(N^0.5)
    int kthFactor(int n, int k){
        vector<int> v1;
        vector<int> v2;
        
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(i*i==n){
                    v1.push_back(i);
                }
                else{
                    v1.push_back(i);
                    v2.push_back(n/i);
                }
            }
        }
        reverse(begin(v2),end(v2));
        if(k>(v1.size()+v2.size())) return -1;
        else if(k<=v1.size()) return v1[k-1];
        else return v2[k-v1.size()-1];
    }
};