class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        int n = v.size();
        vector<int> nge(n, -1);
        vector<int> pse(n, -1);
        stack<int> s;
        
        for(int i = 0; i < n; i++){
            while(!s.empty() && v[s.top()] < v[i]){
                nge[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        // Reset the stack for the second loop
        stack<int>().swap(s); // Clear the stack

        for(int i = 0; i < n; i++){
            while (!s.empty() && v[s.top()] >= v[i]) {
                s.pop();
            }

            if (!s.empty()) {
                pse[i] = s.top();
            }

            s.push(i);
        }
        
        for(int i = 0; i < v.size(); i++){
            if(pse[i] != -1 && nge[i] != -1) return true;
        }
        return false;
    }
};
