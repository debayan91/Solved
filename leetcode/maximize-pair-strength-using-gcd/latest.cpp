class Solution {
public:
    long long gcd(long long a, long long b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    long long maxPairStrength(vector<int>& nums) {
        int n = size(nums);
        long long mx = 1;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                long long g = gcd(1LL *nums[i], nums[j]);
                mx = max(mx, (1LL * nums[i] * nums[j]) / (g * g));
            }
        }
        return mx;
    }
};