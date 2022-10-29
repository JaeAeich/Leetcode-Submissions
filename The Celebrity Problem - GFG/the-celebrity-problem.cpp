//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& v, int n) 
    {
    
        for(int i=0;i<v.size();i++){
            bool f=true;
            for(int j=0;j<v.size();++j){
                if(v[i][j]) {
                    f=false;
                    break;
                }
            }
            if(f==true){
                bool fl=true;
                for(int k=0;k<v.size();k++){
                    if(i!=k && !v[k][i]){
                        fl=false;
                        break;
                    }                
                }
                if(fl) return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends