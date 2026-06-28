class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long sum = LLONG_MIN;

        long long a = LLONG_MIN; // past
        long long b = LLONG_MIN;
        long long c = LLONG_MIN;

        for (int i = 0; i < size(nums); i++) {
            long long p = 1LL * nums[i] * k;

            long long aprev = a;
            long long bprev = b;
            long long cprev = c;

            if (aprev == LLONG_MIN) {
                a = nums[i];
            } else {
                a = max(aprev + nums[i], 1LL * nums[i]);
            }

            b = p;

            if (aprev != LLONG_MIN) {
                b = max(b, aprev + p);
            }
            if (bprev != LLONG_MIN) {
                b = max(b, bprev + p);
            }

            c = LLONG_MIN;

            if (cprev == LLONG_MIN) {

            } else {
                c = cprev + nums[i];
            }

            if (bprev != LLONG_MIN) {
                c = max(c, bprev + nums[i]);
            }

            sum = max(sum, max(c, max(a, b)));
        }

        a = LLONG_MIN; // past
        b = LLONG_MIN;
        c = LLONG_MIN;

        for (int i = 0; i < size(nums); i++) {
            long long p = 1LL * nums[i] * k;

            long long aprev = a;
            long long bprev = b;
            long long cprev = c;

            if(nums[i] < 0){
                p = (-nums[i]) / k;
                p = -p;
            }else{
                p = nums[i] / k;
            }

            if (aprev == LLONG_MIN) {
                a = nums[i];
            } else {
                a = max(aprev + nums[i], 1LL * nums[i]);
            }

            b = p;

            if (aprev != LLONG_MIN) {
                b = max(b, aprev + p);
            }
            if (bprev != LLONG_MIN) {
                b = max(b, bprev + p);
            }

            c = LLONG_MIN;

            if (cprev == LLONG_MIN) {

            } else {
                c = cprev + nums[i];
            }

            if (bprev != LLONG_MIN) {
                c = max(c, bprev + nums[i]);
            }

            sum = max(sum, max(c, max(a, b)));
        }
        return sum;
    }
};