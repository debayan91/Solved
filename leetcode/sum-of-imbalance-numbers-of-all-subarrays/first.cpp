class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            multiset<int> s;
            int imbalance = 0;

            for (int j = i; j < n; j++) {
                auto it = s.insert(nums[j]);

                // Duplicate doesn't change imbalance
                if ((it != s.begin() && *prev(it) == *it) ||
                    (next(it) != s.end() && *next(it) == *it)) {
                    ans += imbalance;
                    continue;
                }

                auto prv = (it == s.begin()) ? s.end() : prev(it);
                auto nxt = next(it);

                if (prv != s.end() && nxt != s.end()) {
                    // Remove old gap
                    if (*nxt - *prv > 1)
                        imbalance--;

                    // Add new gaps
                    if (*it - *prv > 1)
                        imbalance++;

                    if (*nxt - *it > 1)
                        imbalance++;
                }
                else if (prv != s.end()) {
                    if (*it - *prv > 1)
                        imbalance++;
                }
                else if (nxt != s.end()) {
                    if (*nxt - *it > 1)
                        imbalance++;
                }

                ans += imbalance;
            }
        }

        return ans;
    }
};