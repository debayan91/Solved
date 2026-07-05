class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for(int i : nums){
            int n = i;
            int mn = 9;
            int mx = 0;
            if(n == 0) mn = mx = 0;
            while(n){
                int d = n % 10;
                mn = min(mn, d);
                mx = max(mx, d);
                n /= 10;
            }
            int r = mx - mn;
            m[r] += i;
            res = max(res, r);
        }
        return m[res];
    }
};