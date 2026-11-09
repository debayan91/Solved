class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& time) {
        vector<int> busy(k, 0);
        int n = size(arrival);
        set<int> free;
        for (int i = 0; i < k; i++)
            free.insert(i);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            int t = i % k;
            while (!pq.empty() && pq.top()[0] <= arrival[i]) {
                auto [a, b] = pq.top();
                pq.pop();
                free.insert(b);
            }
            if (free.count(t)) {
                free.erase(t);
                pq.push({arrival[i] + time[i], t});
                busy[t]++;
            } else {
                if (free.empty())
                    continue;
                auto it = free.lower_bound(t);
                int t = *(it != free.end() ? it : free.begin());
                free.erase(t);
                pq.push({arrival[i] + time[i], t});
                busy[t]++;
            }
        }
        int mx = *max_element(begin(busy), end(busy));
        vector<int> res;
        for (int i = 0; i < k; i++)
            if (busy[i] == mx)
                res.push_back(i);
        return res;
    }
};