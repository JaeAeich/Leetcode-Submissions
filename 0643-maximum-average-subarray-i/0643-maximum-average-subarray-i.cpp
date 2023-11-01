class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        double ans = INT_MIN;
        int sum = 0;

        // Calculate the sum of the first 'k' elements
        for (int i = 0; i < k; i++) {
            sum += v[i];
        }

        // Initialize 'ans' with the average of the first 'k' elements
        ans = static_cast<double>(sum) / k;

        // Slide the window and update 'ans'
        for (int i = k; i < v.size(); i++) {
            sum += v[i] - v[i - k]; // Add the new element and subtract the old element
            ans = max(ans, static_cast<double>(sum) / k);
        }

        return ans;
    }
};
