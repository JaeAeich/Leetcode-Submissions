class Solution {
public:
    //Moore's voting algorith, O(N)
    int majorityElement(vector<int>& v) {
        int m_ele=0,c=0;
        for(int i=0;i<v.size();i++){
            // if count becomes zero assume that iht ele is the majority ele.
            if(c==0){
                m_ele=v[i];
            }
            //If assumed ith ele is same as assumed majority ele, increase count.
            if(v[i]==m_ele){
                c++;
            }
            else {
                c--;
            }
        }
        return m_ele;
    }
};