class Solution {
public:
    //In binary func true is all the nums greater than or equal to t.
    //Finding the first t.
    int lb_firstF(vector<int> &v, int t){
        int lo=0,hi=v.size()-1;
        int ans=-1;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            
            if(v[mid]>=t) ans=mid,hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }
    //In binary func true is all the nums less than or equal to t.
    //Finding the last t.
    int lb_lastT(vector<int> &v, int t){
        int lo=0,hi=v.size()-1;
        int ans=-1;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            
            if(v[mid]<=t) ans=mid,lo=mid+1;
            else hi=mid-1;
        }
        return ans;
    }
    //Binary search
    vector<int> searchRange(vector<int>& v, int t) {
        int idx1=lb_firstF(v,t);
        int idx2=lb_lastT(v,t);
        vector<int> ans;
        
        if(idx1<v.size() && v[idx1]==t) ans.push_back(idx1);
        else ans.push_back(-1);
        if(idx2<v.size() && v[idx2]==t ) ans.push_back(idx2);
        else ans.push_back(-1);
        return ans;
    }
};