class Solution {
private:
    vector<vector<int>> dp;

    int helper(string& s, string& t, int i, int j) {
        if (i >= s.size()) {
            int retHere = 0;
            while (j < t.size()) retHere += int(t[j++]);
            return retHere;
        }

        if (j >= t.size()) {
            int retHere = 0;
            while (i < s.size()) retHere += int(s[i++]);
            return retHere;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int ret = 0;

        if (s[i] == t[j]) {
            ret = helper(s, t, i + 1, j + 1);
        } else {
            int delT = int(t[j]) + helper(s, t, i, j + 1);
            int delS = int(s[i]) + helper(s, t, i + 1, j);

            ret = min(delT, delS);
        }

        return dp[i][j] = ret;
    }

public:
    int minimumDeleteSum(string s, string t) {
        int n = s.size(), m = t.size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        return helper(s, t, 0, 0);
    }
};
