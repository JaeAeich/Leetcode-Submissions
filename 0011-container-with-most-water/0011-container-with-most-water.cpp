class Solution {
public:
    int maxArea(vector<int>& v) {
        int ans=0;
        for(int i=0,j=v.size()-1;i<j;){
            //checking how much water ith and jth lines will hold.
            ans=max(ans,(j-i)*min(v[i],v[j]));
            //keeping the longest line (greedily).
            if(v[i]>v[j]) j--;
            else if(v[i]<v[j]) i++;
            //if both the lines are equal,jumping to the next longest line.
            else {
                if(v[i+1]>v[j-1]) i++;
                else j--;
            }
        }
        return ans;
    }
};