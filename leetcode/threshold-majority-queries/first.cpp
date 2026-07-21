class Solution {
public:
    struct Query {
        int l, r, threshold, idx;
    };

    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int B = sqrt(n);

        // Coordinate compress
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> comp(n);
        for (int i = 0; i < n; i++)
            comp[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();

        vector<Query> qs;
        for (int i = 0; i < q; i++) {
            qs.push_back({
                queries[i][0],
                queries[i][1],
                queries[i][2],
                i
            });
        }

        sort(qs.begin(), qs.end(), [&](const Query &a, const Query &b) {
            int ba = a.l / B;
            int bb = b.l / B;
            if (ba != bb) return ba < bb;
            return a.r < b.r;
        });

        vector<int> freq(vals.size(), 0);

        int curL = 0;
        int curR = -1;

        auto add = [&](int idx) {
            freq[comp[idx]]++;
        };

        auto remove = [&](int idx) {
            freq[comp[idx]]--;
        };

        vector<int> ans(q);

        for (auto &qq : qs) {

            while (curL > qq.l) add(--curL);
            while (curR < qq.r) add(++curR);
            while (curL < qq.l) remove(curL++);
            while (curR > qq.r) remove(curR--);

            int bestFreq = 0;
            int bestVal = -1;

            for (int id = 0; id < (int)vals.size(); id++) {
                if (freq[id] >= qq.threshold) {
                    if (freq[id] > bestFreq ||
                        (freq[id] == bestFreq && vals[id] < bestVal)) {
                        bestFreq = freq[id];
                        bestVal = vals[id];
                    }
                }
            }

            ans[qq.idx] = bestVal;
        }

        return ans;
    }
};