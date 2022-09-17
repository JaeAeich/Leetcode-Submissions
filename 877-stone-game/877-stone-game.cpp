class Solution {
public:
    bool stoneGame(vector<int>& v) {
        int aStone=0,bStone=0;
        int n=v.size();
        int c=0;
        for(int i=0,j=n-1;i<=j;){
            int temp=0;
            if(v[i]>v[j]){
                temp=v[i++];
            } 
            else temp=v[j--];
            if(c&1) bStone+=temp;
            else aStone+=temp;
        }
        return aStone>bStone;
    }
};