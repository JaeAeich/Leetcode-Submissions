class Solution {
public:
    // // Selection sort O(N^2).
    // void sortColors(vector<int>& v) {
    //     int n=v.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             //swap the greater element with the smallest one.
    //             if(v[j]<v[i]){
    //                 swap(v[i],v[j]);
    //             }
    //         }
    //     }
    // }
    
    // Count Sort O(N)
    void sortColors(vector<int>& v) {
        vector<int> count={0,0,0};
        // count the frequecy of each distinc element.
        for(int i=0;i<v.size();i++){
            count[v[i]]++;
        }
        int j=0;
        // Till freq of ith element becomes zero push that into the vector.
        for(int i=0;i<3;i++){
            while(count[i]){
                v[j]=i;
                j++;
                count[i]--;
            }
        }
    }
};