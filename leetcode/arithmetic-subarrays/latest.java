class Solution {
    public Boolean inAP(int n, int min, int max, long sum, long sumSq) {
        if (n <= 1)
            return true;
        if ((max - min) % (n - 1) != 0)
            return false;

        long d = (max - min) / (n - 1);
        if (sum * 2 != (long) n * (min + max))
            return false;

        long a = min;
        long n_long = n;
        long term1 = n_long * a * a;
        long term2 = d * a * n_long * (n_long - 1);
        long term3 = (d * d * n_long * (n_long - 1) * (2 * n_long - 1)) / 6;

        long expectedSumSq = term1 + term2 + term3;

        return sumSq == expectedSumSq;
    }

    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> res = new ArrayList<>();
        int n = l.length;
        for (int k = 0; k < n; k++) {

            int start = l[k];
            int end = r[k];

            int min = Integer.MAX_VALUE;
            int max = Integer.MIN_VALUE;

            long sum = 0;
            long sumSq = 0;

            for (int i = start; i < end + 1; i++) {
                if (nums[i] < min)
                    min = nums[i];
                if (nums[i] > max)
                    max = nums[i];
                sum += nums[i];
                sumSq += nums[i] * nums[i];
            }

            res.add(inAP(end - start + 1, min, max, sum, sumSq));
        }
        return res;
    }
}