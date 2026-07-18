class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int mod = 1e9 + 7;
        unsigned long int p = 0, q = 0, r = 0;
        unsigned long int changes = 0;
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] < a) {
                // p = (p + 1) % mod;
                p++;
                unsigned long int k = q + r;
                changes = (changes + k) % mod;
            } else if (nums[i] <= b) {
                
                changes = (changes + r) % mod;
                 //q = (q + 1) % mod;
                q++;
            } else {
                //r = (r + 1) % mod;
                r++;
            }
        }
        changes %= mod;
        return (int)changes;
    }
};