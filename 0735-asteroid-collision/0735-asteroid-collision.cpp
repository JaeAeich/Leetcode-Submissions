class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int> s;
        for(int i=0;i<v.size();i++){
            if(s.empty() || v[i]>0 || (s.empty() && v[i]<0) || v[i]*s.top()>0){
                s.push(v[i]);
            }
            else{
                while(!s.empty() && abs(s.top())<abs(v[i]) && s.top()*v[i]<0){
                    s.pop();
                }
                if(s.empty()){
                    s.push(v[i]);
                    continue;
                }
                if(s.top() * v[i]>0){
                    s.push(v[i]);
                    continue;
                }
                if(abs(s.top())>abs(v[i]) && v[i]*s.top()<0){
                    continue;
                }
                if(abs(s.top())==abs(v[i]) && v[i]*s.top()<0){
                    s.pop();
                    continue;
                }
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};