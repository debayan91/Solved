class Solution {
public:
    int ok(int a) {
        int count = 0;
        int sum = 0;
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                if (i * i == a) {
                    sum += i;
                    count++;
                } else {
                    sum += i + a / i;
                    count += 2;
                }
                //---
                if (count > 4)
                    return 0;
            }
        }
        if (count == 4)
            return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
            sum += ok(i);
        return sum;
    }
};