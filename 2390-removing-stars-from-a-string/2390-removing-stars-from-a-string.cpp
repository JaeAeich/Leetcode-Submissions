class Solution {
public:
    string removeStars(string s) {
        deque<char> dq;
        for(auto c: s){
            if(c == '*' && !dq.empty()) dq.pop_back();
            else dq.push_back(c);
        }
        string ans = "";
        while(!dq.empty()){
            ans += dq.front();
            dq.pop_front();
        }
        return ans;
    }
};