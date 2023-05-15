class Solution {
public:
    //Dutch national Flag Algorithm
    void sortColors(vector<int>& v) {
        int lo=0,mid=0,hi=v.size()-1;
        while(mid<=hi){
            if(v[mid]==0){
                swap(v[mid],v[lo]);
                lo++;
                mid++;
            }
            else if(v[mid]==2){
                swap(v[mid],v[hi]);
                hi--;
            }
            else if(v[mid]==1) mid++;
        }
    }
};