class Solution {
public:
    //Using Stl funct.
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
        int idx_last=upper_bound(v.begin(),v.end(),t)-begin(v);
        ans.push_back(--idx_last);
        return ans;
    }
};