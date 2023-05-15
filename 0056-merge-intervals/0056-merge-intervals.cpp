class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& v) {
        //sort it wrt starting time.
        sort(begin(v),end(v),cmp);
        vector<vector<int>> ans={};
        int s=v[0][0];
        int e=v[0][1];
        /*
        If the ith interval starts before the perevious interval
        ends then that means there is an overlap, if this interval 
        ends after prev interval then we will update the ending time
        as the inteval has been merged.
        */
        for(int i=0;i<v.size();i++){
            if(v[i][0]<=e){
                if(v[i][1]>e) e=v[i][1];
            }
            else{
                ans.push_back({s,e});
                s=v[i][0];
                e=v[i][1];
            }
        }
        /*
        We will push the last entry as well as, no matter
        which loop the last interval ends up ie first or second,
        it will not be pushed.
        */
        ans.push_back({s,e});
        return ans;
    }
};