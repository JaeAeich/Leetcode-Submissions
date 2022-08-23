class Solution {
public:
    // Storing neg and pos values separately.
    // Time complexity :-O(N), Space Complexity :- O(N)
    vector<int> rearrangeArray(vector<int>& v) {
        queue<int> pos,neg;
        for(int val:v){
            if(val>0){
                pos.push(val);
            }
            else{
                neg.push(val);
            }
        }
        for(int i=0;i<v.size();i++){
            if(i%2==0){
                v[i]=pos.front();
                pos.pop();
            }
            else{
                v[i]=neg.front();
                neg.pop();
            }
        }
        return v;
    }
};