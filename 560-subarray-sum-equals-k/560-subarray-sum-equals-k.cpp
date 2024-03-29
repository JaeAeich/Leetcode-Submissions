class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        // int n=v.size();
        // int c=0;
        // int sum=0;
        // //Hash map that will store frequency of all the prefix sum.
        // map<int,int> m;
        // //Pushing 0 becuase subarray can start from index .
        // m[0]=1;
        // for(int i=0;i<n;i++){
        //     sum+=v[i];
        //     //If we have sum-k in Hashmap, then our total count will be incremented by that frequency. 
        //     if(m.find(sum-k)!=m.end()){
        //         c+=m[sum-k];
        //     }
        //     //Else push the prefix sum into the Hashmap or increase its freq if already present.
        //     m[sum]++;
        // }
        // return c;
        
        int n=v.size();
        map<int,int> m;
        m[0]=1;
        int sum=0,c=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(m.find(sum-k)!=m.end()){
                c+=m[sum-k];
            }
            m[sum]++;
        }
        return c;
    }
};















