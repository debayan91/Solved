class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int mx = 0;
        for(auto& a : nums){
            mx = max(mx, a[1]);
        }
        vector<int> r(mx + 2, 0);
        for(auto& a : nums){
            for(int i = a[0]; i <= a[1]; i++) r[i] = 1;
        }
        return accumulate(begin(r), end(r), 0);
    }
};