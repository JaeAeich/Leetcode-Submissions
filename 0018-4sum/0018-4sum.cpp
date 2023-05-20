class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int t) {
        int n = v.size();
        vector<vector<int>> ans;
        // sort the array to use two pointers
        sort(begin(v),end(v));
        for(int i=0;i<n;i++){
            // if already taken this as the first ele, skip
            if(i>0 && v[i]==v[i-1]) continue;
            // if already take this as the second ele, skip
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && v[j]==v[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    // add incrementally other wise overflow might happen
                    long long int sum = v[i] + v[j];
                    sum+=v[k];
                    sum+=v[l];
                    if(sum<t){
                        k++;
                    }
                    else if(sum>t){
                        l--;
                    }
                    else{
                        ans.push_back({v[i],v[j],v[k],v[l]});
                        //store the vals so that skip over the same ones
                        int kval = v[k],lval=v[l];
                        do{
                            k++;
                        }while(k<l && v[k]==kval);
                        do{
                            l--;
                        }while(l>k && v[l]==lval);
                    }
                }
            }
        }
        return ans;
    }
};