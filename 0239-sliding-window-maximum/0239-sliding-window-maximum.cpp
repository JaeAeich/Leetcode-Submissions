class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int i = 0, j = 0;
        deque<int> dq;
        int n = v.size();
        vector<int> ans = {};
        while(k--){
            while(!dq.empty() && v[j] > v[dq.back()]) dq.pop_back();
            dq.push_back(j++);
        }
        ans.push_back(v[dq.front()]);
        while(j < n){
            while(!dq.empty() && v[dq.back()] < v[j]) dq.pop_back();
            dq.push_back(j++);
            i++;
            while(dq.front() < i) dq.pop_front();
            int idx = dq.front();
            ans.push_back(v[idx]);
        }
        return ans;
    }
};