class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &v)
    {
        // top, left , bottom, right pointer to make matrix smaller .
        int t = 0, b = v.size() - 1, l = 0, r = v[0].size() - 1;
        vector<int> ans;
        int c = 1;
        // direction variable
        int dir = 0;
        while (t <= b && l <= r)
        {
            // left to right traversal
            if (dir == 0)
            {
                for (int i = l; i <= r; i++)
                {
                    ans.push_back(v[t][i]);
                }
                // increasing top var so that , that row is not visited again.
                t++;
            }
            // for top to bottom
            if (dir == 1)
            {
                for (int i = t; i <= b; i++)
                {
                    ans.push_back(v[i][r]);
                }
                r--;
            }
            // for right to left
            if (dir == 2)
            {
                for (int i = r; i >= l; i--)
                {
                    ans.push_back(v[b][i]);
                }
                b--;
            }
            // for bottom to top
            if (dir == 3)
            {
                for (int i = b; i >= t; i--)
                {
                    ans.push_back(v[i][l]);
                }
                l++;
            }
            dir = (++dir) % 4;
        }
        return ans;
    }
};