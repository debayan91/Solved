class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0;
        for(auto i : nums) xr ^= (long long)i;
        long long bit = xr & (-xr);
        long long a = xr, b = xr;
        for(auto i : nums){
            if(i & bit) a ^= i;
            else b ^= i;
        }
        return {(int)a, (int)b};
    }
};