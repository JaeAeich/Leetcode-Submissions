class Solution {
private:
    // final ans to be returned
    vector<vector<int>> finans = {};

    void helper(vector<int> v, vector<int> ans = {}, int i = 0)
    {
        // Base case
        if (i >= v.size())
        {
            finans.push_back(ans);
            return;
        }

        // Pick this ele
        ans.push_back(v[i]);
        helper(v, ans, i + 1);
        ans.pop_back();

        // leave this ele and don't pick it in this iteration
        while (i + 1 < v.size() && v[i] == v[i + 1])
            i++;
        helper(v, ans, i + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &v)
    {

        // Sort the array so as to remove duplicate while picking and not picking
        sort(begin(v), end(v));
        helper(v);
        return finans;
    }
};