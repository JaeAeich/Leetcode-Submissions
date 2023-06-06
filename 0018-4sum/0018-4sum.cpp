class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int t) {
        int n = v.size();
        vector<vector<int>> ans = {};
        
        // Sort to use two-pointer
        sort(begin(v),end(v));
        
        for(int i=0;i<n-3;i++){
            
            // Remove duplicate value
            if(i && v[i]==v[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                
                // Remove duplicate value
                if(j>i+1 && v[j]==v[j-1]) continue;
                int k = j+1, l = n-1;
                while(k<l){
                    
                    // Don't use sum = v[i]+v[j]+v[k]+v[l]
                    long long int sum = v[i];
                    sum+=v[j];
                    sum+=v[k];
                    sum+=v[l];
                    if(sum==t){
                        ans.push_back({v[i],v[j],v[k],v[l]});
                        do{
                            k++;
                        }while(k<=l && v[k]==v[k-1]);
                        do{
                            l--;
                        }while(k<=l && v[l]==v[l+1]);
                    }
                    else if(sum<t) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};