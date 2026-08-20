class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = size(nums), res = 0;
        unordered_map<int, int> m;

        m[0] = 1;

        vector<int> prefix(n + 1, 0);

        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];

            int a = prefix[i] % k;
            if(a < 0) a += k;

            m[a]++;
        }

        for(auto& [a, b] : m)
            res += b * (b - 1) / 2;

        return res;
    }
};