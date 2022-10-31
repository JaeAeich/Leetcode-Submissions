class Solution {
public:
    //Naive approach ,O(N^2)
    // int largestRectangleArea(vector<int>& v) {
    //     int ans=INT_MIN;
    //     for(int i=0;i<v.size();i++){
    //         int area=0;
    //         for(int j=i;j<v.size() && v[j]>=v[i];j++){
    //             area+=v[i];
    //         }
    //         for(int j=i-1;j>=0 && v[j]>=v[i];j--){
    //             area+=v[i];
    //         }
    //         ans=max(ans,area);
    //     }
    //     return ans;
    // }    
    int largestRectangleArea(vector<int>& v) {
        int n=v.size();
        stack<int> s;
        vector<int> nle(n,-1);
        vector<int> ple(n,-1);
        for(int i=0;i<v.size();++i){
            while(!s.empty() && v[s.top()]>=v[i]){
                nle[s.top()]=i;
                s.pop();
            }
            if(!s.empty()) ple[i]=s.top();
            s.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<v.size();i++){
            int n=nle[i];
            int p=ple[i];
            int f=n-p-1;
            if(p==-1 && n!=-1) f=n;
            else if(p!=-1 && n==-1) f=v.size()-p-1;
            else if(n==-1 && p==-1) f=v.size();
            ans=max(ans,(v[i]*f));
        }
        return ans;
    }

};











