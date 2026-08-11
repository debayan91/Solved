class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend()); // decreasing
        int l = jobs[0], r = accumulate(jobs.begin(), jobs.end(), 0), res = r;
        auto works = [&](int mx) { // if all have a sum of mx, can there be <= k groups
            vector<int> load(k, 0);
            auto dfs = [&](auto&& self, int i) -> bool {
                if (i == jobs.size()) return 1; // finished all jobs
                for (int w = 0; w < k; w++) {
                    if (load[w] + jobs[i] > mx) continue; // more than mx in group
                    load[w] += jobs[i];
                    if (self(self, i + 1)) return 1; // if backtrack(index +1)
                    load[w] -= jobs[i]; // remove job
                    if (load[w] == 0 || load[w] + jobs[i] == mx) break; // if we finished or reached mx
                }
                return 0;
            };
            return dfs(dfs, 0);
        };
        while (l <= r) { // bs on res
            int m = l + (r - l) / 2;
            if (works(m)) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};