class Solution {
public:
    void reverseString(vector<char>& v) {
        // if size is 1 reverse is same as the original.
        if(v.size()==1) return;
        
        
        stack<char> st;
        // pushing all the chars int a stack.
        for(int i=0;i<v.size();i++){
            st.push(v[i]);
        }
        // clearing the vector.
        v.clear();
        //pushing the top element of the stack in vector.
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
    }
};