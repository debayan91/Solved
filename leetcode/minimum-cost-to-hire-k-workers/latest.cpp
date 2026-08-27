class Solution {
public:
    double mincostToHireWorkers(vector<int>& dishes, vector<int>& min_fee, int k) {
        int n = dishes.size();
        double ans = numeric_limits<double>::max();
        double sum = 0;

        vector<pair<double, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {(double)min_fee[i] / dishes[i], dishes[i]};

        sort(v.begin(), v.end());

        priority_queue<int> pq;

        for (auto [ratio, d] : v) {
            pq.push(d);
            sum += d;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k)
                ans = min(ans, sum * ratio);
        }

        return ans;
    }
};