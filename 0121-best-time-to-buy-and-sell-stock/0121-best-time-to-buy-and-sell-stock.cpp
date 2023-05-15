class Solution {
public:
    int maxProfit(vector<int>& v) {
        //Atleast the ans will 0, ie sold on the same day.
        int ans = 0;
        int prev = v[0];
        for(int i = 1;i<v.size();i++){
            //if selling on the ith day is no profitable, this means it better to buy on this day.
            if(v[i]-prev<0){
                prev=v[i];
            }
            ans = max(ans,v[i]-prev);
        }
        return ans;
    }
};