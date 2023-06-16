//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> finans={};
    
    void helper(vector<int> v, int i=0,  int ans =0){
        if(i>=v.size()){
            finans.push_back(ans);
            return ;
        }
        
        ans += v[i];
        helper(v,i+1,ans);
        ans-=v[i];
        helper(v,i+1,ans);
    }
    
    vector<int> subsetSums(vector<int> v, int N)
    {
        // Write Your Code here
        helper(v);
        return finans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends