class Solution {
public:
    //brute force ,using hash map
    int majorityElement(vector<int>& v) {
        map<int,int> m;
        //counting freq
        for(int val:v){
            m[val]++;
        }
        int maj_num=NULL;
        int freq=0;
        //Looping through map and finding the max frequency.
        for(auto it=begin(m);it!=end(m);it++){
            if(!maj_num || (maj_num<it->first && freq<it->second)){
                maj_num=it->first;
                freq=it->second;
            }
        }
        return maj_num;
    }
};