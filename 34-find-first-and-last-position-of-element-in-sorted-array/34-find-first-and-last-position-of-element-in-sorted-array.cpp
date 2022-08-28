class Solution {
public:
    vector<int> searchRange(vector<int>& v, int t) {
        //Finding the first occurance of t.
        auto it=lower_bound(begin(v),end(v),t);
        int n=v.size();
        //If t isn't present in v , return {-1,-1}.
        if(it==v.end() || *it!=t){
            return {-1,-1};
        }
        vector<int> ans;
        int idx=it-begin(v);
        ans.push_back(idx);
        //Finding the last occurance of t.
        for(int i=idx;i<n;i++){
            if(i==n-1 && v[i]==t){
                ans.push_back(i);
                break;
            }
            if(i+1<n && v[i+1]!=t){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};