class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int mx = 0;
        int i = 0;
        int n = size(nums);
        unordered_map<int, int> m;
        int start = i;
        while (i < n) {
            while (i < n && m.size() < 3) {
                m[nums[i]] = i;
                i++;
            }
            if(m.size() < 3){
                int len = i - start;
                mx = max(mx, len);
                continue;
            }
            int rem, mxx = INT_MAX;
            for (auto& [a, b] : m) {
                if (b < mxx) {
                    mxx = b;
                    rem = a;
                }
            }
            int len = i == n ? n - 1 - start : i - 1 - start;
            mx = max(mx, len);
            start = mxx + 1;
            m.erase(rem);
        }
        return mx;
    }
};