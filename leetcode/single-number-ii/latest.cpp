class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (int x : nums) {
            ones ^= (x & ~twos);
            twos ^= (x & ~ones);
        }

        return ones;
    }
};