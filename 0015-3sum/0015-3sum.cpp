class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        // sort the array to use two pointers.
        sort(begin(v),end(v));
        for(int i=0;i<n;i++){
            // if this ele has been processed move.
            if(i>0 && v[i]==v[i-1]) continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum = v[i]+v[j]+v[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    ans.push_back({v[i],v[j],v[k]});
                    int jval=v[j],kval=v[k];
                    /* 
                    move atleast once and then if still at the same ele to avoid redundancy 
                    keep moving till a different ele is found.
                    */
                    do{
                        j++;
                    }while(j<k && v[j]==jval);
                    do{
                        k--;
                    }while(k>j && v[k]==kval);
                }
            }
        }
        return ans;
    }
};