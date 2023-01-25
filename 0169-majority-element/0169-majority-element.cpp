class Solution {
public:
    // //brute force ,using hash map
    // int majorityElement(vector<int>& v) {
    //     map<int,int> m;
    //     //counting freq
    //     for(int val:v){
    //         m[val]++;
    //     }
    //     int maj_num=NULL;
    //     int freq=0;
    //     //Looping through map and finding the max frequency.
    //     for(auto it=begin(m);it!=end(m);it++){
    //         if(!maj_num || (maj_num<it->first && freq<it->second)){
    //             maj_num=it->first;
    //             freq=it->second;
    //         }
    //     }
    //     return maj_num;
    // }
    
    //Moore's voting algo
    int majorityElement(vector<int>& v) {
        //assume first ele to be maj with freq 1.
        int maj_ele = v[0],c=1;
        /*
        loop thought the array if an ele with higher freq exists update maj_ele 
        and c.
        */
        for(int i=1;i<v.size();i++){
            //if c becomes zero then curr ele is maj ele.
            if(c==0){
                maj_ele=v[i];
            }
            //if curr ele is same as maj ele , increase freq.
            if(maj_ele==v[i]){
                c++;
            }
            //else decrease freq.
            else c--;
        }
        return maj_ele;
    }

};