class Solution {
private:
    unordered_map<int, long long> memo;

    long long helper(vector<int> &v, vector<int> &c, int i) {
        if (i >= v.size()) return 0;

        if (memo.find(i) != memo.end()) {
            return memo[i];
        }

        long long ans = LLONG_MAX;

        long long oneDay = c[0] + helper(v, c, i + 1);

        // 7 days
        int j = i;
        while (j < v.size() && v[j] <= v[i] + 6) j++;
        long long sevenDay = c[1] + helper(v, c, j);

        // 30 days
        j = i;
        while (j < v.size() && v[j] <= v[i] + 29) j++;
        long long thirtyDay = c[2] + helper(v, c, j);

        ans = min(ans, min(oneDay, min(sevenDay, thirtyDay)));

        memo[i] = ans;
        return ans;
    }

public:
    int mincostTickets(vector<int>& v, vector<int>& c) {
        return static_cast<int>(helper(v, c, 0));
    }
};
